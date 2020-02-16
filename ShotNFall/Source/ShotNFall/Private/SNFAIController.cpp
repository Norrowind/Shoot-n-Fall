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
#include "Public/CustomNavigationData.h"


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
	DistanceToJump = 500.f;
	DistanceToMoveToTarget = 500.f;
	JumpTime = 0.08f;
	SlideAcceleration = 500.f;
	bIsStunned = false;


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

	//Searching for enemy
	TArray< AShotNFallCharacter*>CharacterPool = GameMode->GetCharacterPool();
	if (CharacterPool.Num() != 0)
	{
		SearchForEnemies();
	}

	//Bounding delegate function to handle projectile hitting
	if (AICharacter)
	{
		AICharacter->GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ASNFAIController::OnHit);
	}

}

//When current enemy dies, set new enemy which is closest to AI character
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

//Searching for enemy in character pool 
void ASNFAIController::SearchForEnemies()
{
	UE_LOG(LogTemp, Warning, TEXT("SearchForEnemies called!"))
	if (GameMode)
	{
		//If only one AI Character exist - check every 3 seconds for new spawned character...
		if (GameMode->GetCharacterPool().Num() <= 1)
		{
			FTimerHandle TimerHandle_EnemySearhTimer;
			GetWorldTimerManager().SetTimer(TimerHandle_EnemySearhTimer, this, &ASNFAIController::SearchForEnemies, 3.f);
		}
		else
		{
			//...if other characters exist on the level - get the nearest one and set enemy 
			EnemyCharacter = GetNearestEnemy(GameMode->GetCharacterPool());
		}
	}
}

//If hit by projectile - stun
void ASNFAIController::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	
	if (Cast<ASNFBasicProjectile>(OtherActor))
	{
		Stun();

	}
	
}

//Delegate which fires by game mode when someone dies
void ASNFAIController::OnCharacterFallen(AShotNFallCharacter* FallenCharacter)
{
	//if dead character is current enemy - search for new one
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

	if (!AICharacter) { return; }

		if (EnemyCharacter)
		{
			ChaseAndShoot(EnemyCharacter);
		}

}


void ASNFAIController::ChaseAndShoot(ACharacter* Target)
{
	if (Target)
	{
		float VerticalLocationDelta = FMath::Abs(Target->GetActorLocation().Z - AICharacter->GetActorLocation().Z);
		float HorizontalLocationDelta = FMath::Abs(Target->GetActorLocation().Y - AICharacter->GetActorLocation().Y);

		//if enemy at right distance- focus on him, check its state(crouching or not) and shoot
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

		//stop shooting and continue to chase the target
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

//small delay before shooting starts for handling automatic weapon fire
void ASNFAIController::Fire()
{
	FTimerHandle TimerHandle_ShootTimer;
	GetWorldTimerManager().SetTimer(TimerHandle_ShootTimer, AICharacter, &AShotNFallCharacter::StartWeaponFire, 0.1f);
}

//delay for more natural looking 
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

//Set Yaw of character to focus on right target
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
			//if bullet was shoot by current enemy and bullet is able to hit character - evade 
			float VerticalLocationDelta = FMath::Abs(Bullet->GetActorLocation().Z - AICharacter->GetActorLocation().Z);
			if ((Bullet->GetOwner() == EnemyCharacter) && VerticalLocationDelta < VerticalDeltaToShoot)
			{
				//randomly choose how to evade - with a jump or crouch
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

			//if someone who shoot ai character is closer than current enemy - set this character as enemy
			if (Cast<ASNFBasicProjectile>(Bullet))
			{
				AActor* DistractingActor = Bullet->GetOwner();
				if (DistractingActor != AICharacter)
				{
					if (DistractingActor && AICharacter && EnemyCharacter)
					{
						float DistanceToDistractingActor = (DistractingActor->GetActorLocation() - AICharacter->GetActorLocation()).Size();
						float DistanceToCurrentTarget = (EnemyCharacter->GetActorLocation() - AICharacter->GetActorLocation()).Size();
						if (DistanceToDistractingActor < DistanceToCurrentTarget)
						{
							EnemyCharacter = Cast<AShotNFallCharacter>(DistractingActor);
						}
					}
				}
			}
		}
	}
}

//Move to target using custom pathfinding logic
void ASNFAIController::MoveToTarget(AActor * Target)
{
	if (!bIsStunned && Target)
	{	
		AShotNFallCharacter* CharacterToFollow = Cast<AShotNFallCharacter>(Target);
		AActor* IntermidiatePathPoint;
		if (CharacterToFollow && AICharacter)
		{

			EndPointActor = CharacterToFollow->GetPlatformCharacterStands();
			StartPointActor = AICharacter->GetPlatformCharacterStands();

			bool IsInAir = AICharacter->GetMovementComponent()->IsFalling();

			//Perform "air control" during jump
			if (IsInAir)
			{
				float Yaw = AICharacter->GetActorRotation().Yaw;
				FRotator CurrentRotation(0.f, Yaw, 0.f);
				AICharacter->GetMovementComponent()->AddInputVector(CurrentRotation.Vector() * 1.f, false);

			}

			if (StartPointActor && EndPointActor)
			{
				//if ai character and enemy are on the same platform - use standart UE4 pathfinding 
				if (EndPointActor == StartPointActor)
				{
					IntermidiatePathPoint = Target;
					MoveToActor(Target, DistanceToMoveToTarget);
				}
				else
				//use custom pathfinding logic 
				{
					FindPath(PathPoints, StartPointActor, EndPointActor, CurrentPathPointIndex);
					if (PathPoints.IsValidIndex(CurrentPathPointIndex))
					{
						IntermidiatePathPoint = PathPoints[CurrentPathPointIndex];
					}
					else
					{
						IntermidiatePathPoint = nullptr;
					}
					JumpOrSlide(IntermidiatePathPoint, StartPointActor, IsInAir);
				}
			}

		}

	}
}

//To handle jump and slide down logic to move beetween platform
void ASNFAIController::JumpOrSlide(AActor * IntermidiatePathPoint, AActor * StartPointActor, bool IsInAir)
{
	if (IntermidiatePathPoint)
	{
		MoveToActor(IntermidiatePathPoint, DistanceToMoveToTarget);

		// if enough close to platform to move to and its above character - jump...
		if (IntermidiatePathPoint->GetActorLocation().Z >= AICharacter->GetActorLocation().Z)
		{
			FVector PlatformEdge = GetPlatformEdgePoint(IntermidiatePathPoint, AICharacter->GetActorLocation());
			if (FMath::Abs(PlatformEdge.Y - AICharacter->GetActorLocation().Y) < DistanceToJump)
			{
				AICharacter->JumpMaxHoldTime = JumpTime;
				AICharacter->Jump();

				//set next point to move to
				CurrentPathPointIndex++;
			}

		}

		// if enough close to platform edge and platform to move below character - slide down...
		else if (IntermidiatePathPoint->GetActorLocation().Z < AICharacter->GetActorLocation().Z)
		{
			FVector PlatformEdge = GetPlatformEdgePoint(StartPointActor, AICharacter->GetActorLocation());
			if (FMath::Abs(PlatformEdge.Y - AICharacter->GetActorLocation().Y) < DistanceToPlatformEdge)
			{
				FVector SlideForwardVelocity = AICharacter->GetActorForwardVector() * SlideAcceleration;
				AICharacter->LaunchCharacter(SlideForwardVelocity, true, false);

				//set next point to move to
				CurrentPathPointIndex++;
			}
		}

		// if landed on the ground - look in direction to move to
		if (!IsInAir)
		{
			LookOnTarget(IntermidiatePathPoint);
		}
	}
}

void ASNFAIController::FindPath(TArray<AActor*>& PathPointsToFill, AActor * From, AActor * To, int32& PathPointIndex)
{
	static AActor* CashedEndPoint = nullptr;

	//if gonna build path for the first time - build path
	if (!CashedEndPoint)
	{
		CashedEndPoint = To;
		ACustomNavigationData::BuildPath(PathPointsToFill, From, To);
		PathPointIndex = 1;
		return;
	}
	
	//if enemy change his location to another platform - rebuild path
	if (CashedEndPoint != To)
	{ 
		CashedEndPoint = To;
		if (PathPointsToFill.Num() > 0)
		{
			PathPointsToFill.Empty();
		}
		ACustomNavigationData::BuildPath(PathPointsToFill, From, To);
		PathPointIndex = 1;
		return;
	}

	else if (PathPointsToFill.Num() > 0)
	{
		//if ai character not loosing the way and moving the right path - no need to rebuild path...
		if (From == PathPointsToFill[PathPointIndex - 1]) { return; }

		//... in another case - reduilt path
		else
		{
			if (PathPointsToFill.Num() > 0)
			{
				PathPointsToFill.Empty();
			}
			ACustomNavigationData::BuildPath(PathPointsToFill, From, To);
			PathPointIndex = 1;
		}
	}


}

//find location of platform edge point which is opposite the character location
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

