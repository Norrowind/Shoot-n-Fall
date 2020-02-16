// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SNFBasicWeapon.h"
#include "SNFShotgun.generated.h"

/**
 * 
 */
UCLASS()
class SHOTNFALL_API ASNFShotgun : public ASNFBasicWeapon
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASNFShotgun();

protected:

	void Fire() override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int32 NumberOfBullets;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BulletPitchRate;
	
};
