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

	AShotNFallCharacter* GetEnemy(const TArray<AShotNFallCharacter *>& CharacterPool);

	void SearchForEnemies();

	void Fire();

	void UnCrouch();

	void Crouch();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnCharacterFallen(AShotNFallCharacter* FallenCharacter);

	void Stun();

	void LookOnTarget(AActor* Target);

	UFUNCTION()
	void NotifyBullets(const TArray<AActor*>& Bullets);

	void MoveToTarget(AActor* Target);

	bool ShouldJump(AActor* CurrentPlatform);

	bool CanJump(AActor* PlatformToCheck, FVector AILocation, FVector GravitationalForce);

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
	float DistanceToMoveToTarget;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	FVector GravitationalForce;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float MovementSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float JumpTime;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float JumpAcceleration;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float SlideAcceleration;

	AActor* TargetToMoveTo;

private:

	void RecoverStun();

	UPROPERTY()
	AShotNFallCharacter* AICharacter;

	UPROPERTY()
	AShotNFallCharacter* EnemyCharacter;

	UPROPERTY()
	AShotNFallGameMode* GameMode;

	AActor* PlatformAIStandsOn;

	UPROPERTY()
	UCapsuleComponent* AINavigationUpCapsule;

	UPROPERTY()
	UCapsuleComponent* AINavigationDownCapsule;

	bool bGonnaJump;

	bool bIsStunned;

	bool bIsAgressive;

	FTimerHandle TimerHandle_StunTimer;




};
