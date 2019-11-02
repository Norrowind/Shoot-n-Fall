// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SNFBasicWeapon.generated.h"

class USkeletalMeshComponent;
class ASNFBasicProjectile;

UCLASS()
class SHOTNFALL_API ASNFBasicWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASNFBasicWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USkeletalMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	UAnimSequence* FireAnimation;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ASNFBasicProjectile>ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName MuzzleSocketName;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float FirePower;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Fire();

};
