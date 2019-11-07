// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SNF_PlatformBuilder.generated.h"

class UStaticMeshComponent;

struct FSpawnPosition
{

	FVector Location;
	float Length;

};

UCLASS()
class SHOTNFALL_API ASNF_PlatformBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASNF_PlatformBuilder();

	void BuildPlatforms();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* GroundPlane;

	UPROPERTY(EditDefaultsOnly, Category = "Platforms")
	TSubclassOf<AActor>PlatformClass;

	UPROPERTY(EditDefaultsOnly, Category = "Platforms")
	int32 MinPlatformsToSpawnFromEachSide;

	UPROPERTY(EditDefaultsOnly, Category = "Platforms")
	int32 MaxPlatformsToSpawnFromEachSide;

	UPROPERTY(EditDefaultsOnly, Category = "Platforms")
	float MinPlatformLength;

	UPROPERTY(EditDefaultsOnly, Category = "Platforms")
	float MaxPlatformLength;

	UPROPERTY(EditDefaultsOnly, Category = "Platforms")
	float DistanceBeetweenPlatforms;

	UPROPERTY(EditDefaultsOnly, Category = "Platforms")
	float PlatformRadius;

private:

	
	AActor * SpawnPlatform(const FSpawnPosition &SpawnPosition);

	TArray<AActor*>SpawnFirstFourPlatforms(AActor* StarterPlatform);

	


};
