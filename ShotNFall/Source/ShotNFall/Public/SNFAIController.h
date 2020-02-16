// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SNFAIController.generated.h"

class AShotNFallCharacter;
class UCapsuleComponent;

/**
*
*/

class UCapsuleComponent;
class UAIPerceptionComponent;
class UAISenseConfig_Sight;
class AShotNFallGameMode;


UCLASS()
class SHOTNFALL_API ASNFAIController : public AAIController
{
	GENERATED_BODY()

public:

	ASNFAIController();

	virtual void Possess(APawn* InPawn) override;

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void ChaseAndShoot(ACharacter* Target);

	AShotNFallCharacter* GetNearestEnemy(const TArray<AShotNFallCharacter *>& CharacterPool);

	void SearchForEnemies();

	void Fire();

	void DelayUnCrouch();

	void DelayCrouch();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnCharacterFallen(AShotNFallCharacter* FallenCharacter);

	void Stun();

	void LookOnTarget(AActor* Target);

	UFUNCTION()
	void NotifyBullets(const TArray<AActor*>& Bullets);

	void MoveToTarget(AActor* Target);

	void JumpOrSlide(AActor * IntermidiatePathPoint, AActor * StartPointActor, bool IsInAir);

	FVector GetPlatformEdgePoint(AActor* PlatformToGet, FVector AILocation);

	UAISenseConfig_Sight* SightConfig;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float VerticalDeltaToShoot;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float BulletSightRadius;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float HorizontalDeltaToShoot;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float DistanceToPlatformEdge;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float DistanceToJump;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float DistanceToMoveToTarget;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float JumpTime;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float JumpAcceleration;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float SlideAcceleration;

private:

	void RecoverStun();

	void FindPath(TArray<AActor*>& PathPoints, AActor* From, AActor* To, int32& PathPointIndex);

	UPROPERTY()
	AShotNFallCharacter* AICharacter;

	UPROPERTY()
	AShotNFallCharacter* EnemyCharacter;

	UPROPERTY()
	AShotNFallGameMode* GameMode;

	UPROPERTY()
	UCapsuleComponent* AINavigationUpCapsule;

	UPROPERTY()
	UCapsuleComponent* AINavigationDownCapsule;

	UPROPERTY()
	TArray<AActor*>PathPoints;

	AActor* StartPointActor;

	AActor* EndPointActor;

	int32 CurrentPathPointIndex;

	bool bGonnaJump;

	bool bIsStunned;

	FTimerHandle TimerHandle_StunTimer;




};
