// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/SNFAIController.h"
#include "Engine/World.h"
#include "ShotNFallCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "ShotNFall.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Public/SNFBasicProjectile.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "ShotNFallGameMode.h"


ASNFAIController::ASNFAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception Component"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	float BulletSightRadius = 700.f;

	SightConfig->SightRadius = BulletSightRadius;
	SightConfig->LoseSightRadius = BulletSightRadius + 20.0f;
	SightConfig->PeripheralVisionAngleDegrees = 90.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	PerceptionComponent->ConfigureSense(*SightConfig);

	PerceptionComponent->ConfigureSense(*SightConfig);
	PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
	PerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ASNFAIController::NotifyBullets);

	VerticalDeltaToShoot = 20.f;
	HorizontalDeltaToShoot = 1500.f;
	DistanceToPlatformEdge = 300.f;
	DistanceToMoveToTarget = 500.f;
	GravitationalForce = FVector(0.f, 0.f, -2.f);
	MovementSpeed = 600.f;
	JumpTime = 0.08f;
	SlideAcceleration = 500.f;
	bGonnaJump = false;
	bIsStunned = false;
	bIsAgressive = true;

}

void ASNFAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ASNFAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	GameMode = Cast<AShotNFallGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->OnFall.AddDynamic(this, &ASNFAIController::OnCharacterFallen);

	AICharacter = Cast< AShotNFallCharacter>(GetPawn());

	if (AICharacter)
	{
		AINavigationDownCapsule = AICharacter->GetAINavigationDownCapsule();
		AINavigationUpCapsule = AICharacter->GetAINavigationUpCapsule();
	}

	TArray< AShotNFallCharacter*>CharacterPool = GameMode->GetCharacterPool();
	if (CharacterPool.Num() != 0)
	{
		SearchForEnemies();
		TargetToMoveTo = EnemyCharacter;

	}

	if (AICharacter)
	{
		AICharacter->GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ASNFAIController::OnHit);
	}

}


AShotNFallCharacter* ASNFAIController::GetNearestEnemy(const TArray<AShotNFallCharacter *>& CharacterPool)
{

	TArray<float>Distances;
	TMap<float, AShotNFallCharacter*>DistancesToCharacters;
	for (auto Character : CharacterPool)
	{
		if (Character != AICharacter)
		{
			float Distance = (AICharacter->GetActorLocation() - Character->GetActorLocation()).Size();
			DistancesToCharacters.Add(Distance, Character);
			Distances.Push(Distance);
		}
	}

	float LeastDistance = Distances[0];
	for (int32 i = 1; i < Distances.Num(); i++)
	{
		if (Distances[i] < LeastDistance)
		{
			LeastDistance = Distances[i];
		}
	}

	AShotNFallCharacter* NearestCharacter = *DistancesToCharacters.Find(LeastDistance);
	return NearestCharacter;

}

void ASNFAIController::SearchForEnemies()
{
	UE_LOG(LogTemp, Warning, TEXT("SearchForEnemies called!"))
	if (GameMode)
	{

		if (GameMode->GetCharacterPool().Num() <= 1)
		{
			FTimerHandle TimerHandle_EnemySearhTimer;
			GetWorldTimerManager().SetTimer(TimerHandle_EnemySearhTimer, this, &ASNFAIController::SearchForEnemies, 3.f);
		}
		else
		{
			EnemyCharacter = GetNearestEnemy(GameMode->GetCharacterPool());
			if (bIsAgressive)
			{
				TargetToMoveTo = EnemyCharacter;
			}
		}
	}
}

void ASNFAIController::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	
	EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
	if (SurfaceType == SURFACE_PLATFORM)
	{
		PlatformAIStandsOn = OtherActor;

	}

	if (Cast<ASNFBasicProjectile>(OtherActor))
	{
		Stun();

	}
	
}

void ASNFAIController::OnCharacterFallen(AShotNFallCharacter* FallenCharacter)
{
	UE_LOG(LogTemp, Warning, TEXT("OnCharacterFallen called!"))
	if (FallenCharacter == EnemyCharacter)
	{
		SearchForEnemies();
	}
}


void ASNFAIController::Stun()
{
	bIsStunned = true;
	AICharacter->GetMovementComponent()->StopMovementImmediately();
	GetWorldTimerManager().SetTimer(TimerHandle_StunTimer, this, &ASNFAIController::RecoverStun, 0.5f);

}

void ASNFAIController::RecoverStun()
{
	bIsStunned = false;
	GetWorldTimerManager().ClearTimer(TimerHandle_StunTimer);
}



void ASNFAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (EnemyCharacter && AICharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s enemy is %s"), *AICharacter->GetName(), *EnemyCharacter->GetName())
	}

	if (!AICharacter) { return; }

	if (bIsAgressive)
	{
		if (EnemyCharacter)
		{
			ChaseAndShoot(EnemyCharacter);
		}

	}
	else
	{
		if (TargetToMoveTo)
		{
			MoveToTarget(TargetToMoveTo);
		}
	}


}



void ASNFAIController::ChaseAndShoot(ACharacter* Target)
{
	if (Target)
	{
		float VerticalLocationDelta = FMath::Abs(Target->GetActorLocation().Z - AICharacter->GetActorLocation().Z);
		float HorizontalLocationDelta = FMath::Abs(Target->GetActorLocation().Y - AICharacter->GetActorLocation().Y);
		if (VerticalLocationDelta < VerticalDeltaToShoot && HorizontalLocationDelta < HorizontalDeltaToShoot)
		{
			LookOnTarget(Target);

			if (Target->bIsCrouched)
			{
				if(!AICharacter->bIsCrouched)
				{
					DelayCrouch();
				}

			}
			else
			{
				if (AICharacter->bIsCrouched)
				{
					DelayUnCrouch();
				}
			}

			Fire();
		}
		else
		{
			AICharacter->StopWeaponFire();
			if (AICharacter->bIsCrouched)
			{
				DelayUnCrouch();
			}
			MoveToTarget(Target);
		}
	}
}


void ASNFAIController::Fire()
{
	FTimerHandle TimerHandle_ShootTimer;
	GetWorldTimerManager().SetTimer(TimerHandle_ShootTimer, AICharacter, &AShotNFallCharacter::StartWeaponFire, 0.1f);
}

void ASNFAIController::DelayCrouch()
{
	FTimerHandle TimerHandle_CrouchDelayTimer;
	GetWorldTimerManager().SetTimer(TimerHandle_CrouchDelayTimer, AICharacter, &AShotNFallCharacter::StartCrouch, 0.2f);
}

void ASNFAIController::DelayUnCrouch()
{
	FTimerHandle TimerHandle_UnCrouchDelayTimer;
	GetWorldTimerManager().SetTimer(TimerHandle_UnCrouchDelayTimer, AICharacter, &AShotNFallCharacter::StopCrouch, 0.2f);
}


void ASNFAIController::LookOnTarget(AActor* Target)
{
	if (!(AICharacter && Target)) { return; }

	if (Target->GetActorLocation().Y > AICharacter->GetActorLocation().Y)
	{

			AICharacter->SetActorRotation(FRotator(0.f, 90.f, 0.f));
	}
	else if (Target->GetActorLocation().Y < AICharacter->GetActorLocation().Y)
	{

			AICharacter->SetActorRotation(FRotator(0.f, -90.f, 0.f));
	}

}

void ASNFAIController::NotifyBullets(const TArray<AActor*>& Bullets)
{
	if (AICharacter)
	{
		for (auto Bullet : Bullets)
		{
			float VerticalLocationDelta = FMath::Abs(Bullet->GetActorLocation().Z - AICharacter->GetActorLocation().Z);
			if ((Bullet->GetOwner() == EnemyCharacter) && VerticalLocationDelta < VerticalDeltaToShoot)
			{
				bool bShouldCrouch = FMath::RandRange(0, 1);
				if (bShouldCrouch)
				{
					if (!AICharacter->bIsCrouched)
					{
						AICharacter->Crouch();
					}
				}
				else
				{
					if (AICharacter->bIsCrouched)
					{
						AICharacter->UnCrouch();
					}
					AICharacter->Jump();
				}

			}

			if (Cast<ASNFBasicProjectile>(Bullet))
			{
				AActor* DistractingActor = Bullet->GetOwner();
				if (DistractingActor != AICharacter)
				{
					float DistanceToDistractingActor = (DistractingActor->GetActorLocation() - AICharacter->GetActorLocation()).Size();
					float DistanceToCurrentTarget = (TargetToMoveTo->GetActorLocation() - AICharacter->GetActorLocation()).Size();
					if (DistanceToDistractingActor < DistanceToCurrentTarget)
					{
						EnemyCharacter = Cast<AShotNFallCharacter>(DistractingActor);
					}
				}
			}
		}
	}
}

void ASNFAIController::MoveToTarget(AActor * Target)
{
	if (!bIsStunned && Target)
	{
		if (AICharacter)
		{
			bool IsInAir = AICharacter->GetMovementComponent()->IsFalling();
			if (!(IsInAir && bGonnaJump))
			{
				LookOnTarget(Target);
			}

			MoveToActor(Target, DistanceToMoveToTarget);

			if (IsInAir && bGonnaJump)
			{
				float Yaw = AICharacter->GetActorRotation().Yaw;
				FRotator CurrentRotation(0.f, Yaw, 0.f);
				AICharacter->GetMovementComponent()->AddInputVector(CurrentRotation.Vector() * 1.f, false);

			}

			if (PlatformAIStandsOn)
			{

				if (ShouldJump(PlatformAIStandsOn) && !IsInAir)
				{

					if (Target->GetActorLocation().Z >= AICharacter->GetActorLocation().Z)
					{
						TArray<AActor*> OverlappingPlatforms;
						AINavigationUpCapsule->GetOverlappingActors(OverlappingPlatforms);
						for (auto Platform : OverlappingPlatforms)
						{
							if (CanJump(Platform, AICharacter->GetActorLocation(), GravitationalForce))
							{

								LookOnTarget(Platform);
								AICharacter->JumpMaxHoldTime = JumpTime;
								AICharacter->Jump();
								break;
							}
						}

					}
					else if (Target->GetActorLocation().Z < AICharacter->GetActorLocation().Z)
					{
						TArray<AActor*> OverlappingPlatforms;
						AINavigationDownCapsule->GetOverlappingActors(OverlappingPlatforms);
						if (OverlappingPlatforms.Num() > 0)
						{
							FVector SlideForwardVelocity = AICharacter->GetActorForwardVector() * SlideAcceleration;
							AICharacter->LaunchCharacter(SlideForwardVelocity, true, false);
						}

					}
				}
			}
		}
	}
}

bool ASNFAIController::ShouldJump(AActor * CurrentPlatform)
{
	FVector Origin;
	FVector BoxExtent;
	CurrentPlatform->GetActorBounds(true, Origin, BoxExtent);

	bool IsNearToLeftEdge = ((Origin + BoxExtent).Y - AICharacter->GetActorLocation().Y) < DistanceToPlatformEdge;
	bool IsNearToRightEdge = FMath::Abs((Origin - BoxExtent).Y - AICharacter->GetActorLocation().Y) < DistanceToPlatformEdge;
	if (IsNearToLeftEdge || IsNearToRightEdge)
	{
		bGonnaJump = true;
		return true;
	}
	else
	{
		bGonnaJump = false;
		return false;
	}
}

bool ASNFAIController::CanJump(AActor* PlatformToCheck, FVector AILocation, FVector GravitationalForce)
{
	FVector EdgePoint = GetPlatformEdgePoint(PlatformToCheck, AILocation);
	float HorizontalDistance = (EdgePoint - AILocation ).Size();
	float TravelTime = HorizontalDistance / MovementSpeed;
	FVector FalloffVector = GravitationalForce / 2 * pow(TravelTime, 2);

	return (AILocation - FalloffVector).Z <= EdgePoint.Z;
	
}

FVector ASNFAIController::GetPlatformEdgePoint(AActor* PlatformToGet, FVector AILocation)
{
	FVector Origin;
	FVector BoxExtent;
	PlatformToGet->GetActorBounds(true, Origin, BoxExtent);

	if (AILocation.Y < PlatformToGet->GetActorLocation().Y)
	{
		return Origin - BoxExtent;
	}
	else
	{
		return Origin + BoxExtent;
	}
}

