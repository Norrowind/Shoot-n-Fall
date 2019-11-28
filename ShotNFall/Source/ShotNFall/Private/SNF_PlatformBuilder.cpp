// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/SNF_PlatformBuilder.h"
#include "Engine/World.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ASNF_PlatformBuilder::ASNF_PlatformBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MinPlatformsToSpawnFromEachSide = 5;
	MaxPlatformsToSpawnFromEachSide = 10;

	MinPlatformLength = 1.0f;
	MaxPlatformLength = 3.0f;

	DistanceBeetweenPlatforms = 200.f;
	PlatformRadius = 200.f;

}



// Called when the game starts or when spawned
void ASNF_PlatformBuilder::BeginPlay()
{
	Super::BeginPlay();
		
}

//Spawns paltforms randomly from each side of base platform, base platform is a root component of this actor
//Platform spawning logic based on arrows components from each side, arrows says in which direction to spawn next platform
TArray<AActor*> ASNF_PlatformBuilder::BuildPlatforms()
{
	TArray<AActor*>SpawnedPlatforms;

	//Generate random number of platforms from each side in given range
	int32 NumberToSpawnFromEachSide = FMath::RandRange(MinPlatformsToSpawnFromEachSide, MaxPlatformsToSpawnFromEachSide);

	// Use to handle last spawning platform
	AActor* LastSpawnedPlatform = this;

	TArray<AActor*>SpawnedFirstFourPlatforms = SpawnFirstFourPlatforms(LastSpawnedPlatform);

	SpawnedPlatforms += SpawnedFirstFourPlatforms;

	//Beacuse we have already spawn 1 platform from each side
	NumberToSpawnFromEachSide--;

	if (SpawnedFirstFourPlatforms.Num() == 0) { return TArray<AActor*>(); }

	for (auto PlatformIterator : SpawnedFirstFourPlatforms)
	{
		LastSpawnedPlatform = PlatformIterator;

		//Spawn random number of platforms from each side
		for (int32 i = 0; i < NumberToSpawnFromEachSide; i++)
		{
			TArray<UActorComponent*>Arrows;

			if (LastSpawnedPlatform)
			{
				TSubclassOf<UArrowComponent>ArrowComponentClass = UArrowComponent::StaticClass();
				Arrows = LastSpawnedPlatform->GetComponentsByClass(ArrowComponentClass);
			}

			//Try spawn platform from each side
			const int32 MAX_TRIES = 4;
			for (int32 i = 0; i < MAX_TRIES; i++)
			{
				//Variable to store location and scale of platform to spawn next
				FSpawnPosition SpawnPosition;

				//Randomly choose the direction to spawn
				int32 RandomDirectionNumber = FMath::RandRange(0, Arrows.Num() - 1);
				UArrowComponent* Arrow = Cast<UArrowComponent>(Arrows[RandomDirectionNumber]);

				if (Arrow)
				{
					FVector StartLocationToTrace = Arrow->GetComponentLocation();
					FVector EndLocationToTrace = StartLocationToTrace + (Arrow->GetComponentRotation().Vector() * DistanceBeetweenPlatforms);

					//Check possibility to spawn platform from given side with sphere cast...
					FHitResult HitResult;
					float Length = FMath::RandRange(MinPlatformLength, MaxPlatformLength);
					bool HasHit = GetWorld()->SweepSingleByChannel
					(
						HitResult, 
						StartLocationToTrace * Length, 
						EndLocationToTrace, 
						FQuat::Identity, 
						ECollisionChannel::ECC_Camera, 
						FCollisionShape::MakeSphere(PlatformRadius)
					);

					if (HasHit)
					{
						//...if cant, remove arrow of this side to check next time
						Arrows.RemoveAt(RandomDirectionNumber);

					}
					else
					{
						//... if can, spawn platform and stop cheking possibility from other sides
						SpawnPosition.Location = EndLocationToTrace;
						SpawnPosition.Length = Length;
						LastSpawnedPlatform = SpawnPlatform(SpawnPosition);
						SpawnedPlatforms.Push(LastSpawnedPlatform);
						break;
					}

				}

			}
		}
	}
	return SpawnedPlatforms;
}


//Spawn single platform and returns it
AActor * ASNF_PlatformBuilder::SpawnPlatform(const FSpawnPosition &SpawnPosition)
{

	AActor* SpawnedPlatform = GetWorld()->SpawnActor<AActor>(PlatformClass, SpawnPosition.Location, FRotator::ZeroRotator);
	if (SpawnedPlatform)
	{
		
		SpawnedPlatform->SetActorScale3D(FVector(1.0f, SpawnPosition.Length, 1.0f));
		SpawnedPlatform->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepWorld, false));
		return SpawnedPlatform;
	}
	else
	{
		return nullptr;
	}
}

// Spawns first four platforms with random scale from each side of base platform, it's used to make balanced, organic looking level 
// Returns array with first four spawning platforms, take base platform as a paraments
TArray<AActor*> ASNF_PlatformBuilder::SpawnFirstFourPlatforms(AActor * StarterPlatform)
{
	TArray<UActorComponent*>Arrows;

	if (StarterPlatform)
	{
			TSubclassOf<UArrowComponent>ArrowComponentClass = UArrowComponent::StaticClass();
			Arrows = StarterPlatform->GetComponentsByClass(ArrowComponentClass);
			TArray<AActor*>SpawnedFirstFourPlatforms;
			for (auto ArrowIterator : Arrows)
			{
				UArrowComponent* Arrow = Cast<UArrowComponent>(ArrowIterator);
				if (Arrow)
				{
					FSpawnPosition SpawnPosition;
					FVector ArrowLocation = Arrow->GetComponentLocation();
					SpawnPosition.Location = ArrowLocation + (Arrow->GetComponentRotation().Vector() * DistanceBeetweenPlatforms);
					SpawnPosition.Length = FMath::RandRange(MinPlatformLength, MaxPlatformLength);
					AActor* SpawnedPlatform = SpawnPlatform(SpawnPosition);
					if (SpawnedPlatform)
					{
						SpawnedFirstFourPlatforms.Push(SpawnedPlatform);
					}
				}
			}
			return SpawnedFirstFourPlatforms;

	}
	return TArray<AActor*>();

}


