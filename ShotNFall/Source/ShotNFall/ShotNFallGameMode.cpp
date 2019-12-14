// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ShotNFallGameMode.h"
#include "ShotNFallCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Public/SNF_PlatformBuilder.h"
#include "Engine/World.h"
#include "ShotNFallCharacter.h"
#include "Public/SNFAIController.h"
#include "TimerManager.h"
#include "Public/CustomNavigationData.h"

AShotNFallGameMode::AShotNFallGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Logic/BP_SNFCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	CharacterSpawnVerticalLocation = FVector(0.f, 0.f, 200.f);
	CenterLevelLocation = FVector(0.f, 0.f, 1000.f);
	RespawnTime = 3.f;
	
}

TArray<AShotNFallCharacter*> AShotNFallGameMode::GetCharacterPool()
{
	return CharactersPool;
}

void AShotNFallGameMode::BeginPlay()
{
	Super::BeginPlay();

	//Spawn level and characters
	ASNF_PlatformBuilder* Builder = GetWorld()->SpawnActor<ASNF_PlatformBuilder>(LevelBuilderClass, CenterLevelLocation, FRotator::ZeroRotator);
	Builder->SetActorScale3D(FVector(1.75f, 15.f, 1.16));
	Platforms = Builder->BuildPlatforms();
	Platforms.Add(Builder);

	ACustomNavigationData::BuildNavigationGraphNodesData(Platforms);

	//Spawn characters and possess controllers
	for(int32 i = 0; i < NumberOfBots + 1; i++)
	{
		FVector PlatformLocation = Platforms[i]->GetActorLocation();
		SpawnCharacter(PlatformLocation, CharactersPool);

	}

	FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator();
	for (auto Character : CharactersPool)
	{
		if (It)
		{
			It->Get()->Possess(Character);
			It++;
		}
		else
		{
			ASNFAIController* AIController = GetWorld()->SpawnActor<ASNFAIController>(AIClass);
			AIController->Possess(Character);
		}
	}

}

void AShotNFallGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	ACustomNavigationData::ClearNavigationData();
}

AShotNFallCharacter* AShotNFallGameMode::SpawnCharacter(const FVector& PlatformLocation, TArray<AShotNFallCharacter*>& CharactersPool)
{
	FVector CharacterSpawnLocation = FVector(0.f, PlatformLocation.Y, PlatformLocation.Z + CharacterSpawnVerticalLocation.Z);

	FRotator CharacterSpawnRotation;
	if (PlatformLocation.Y > 0)
	{
		CharacterSpawnRotation = FRotator(0.f, -100.f, 0.f);
	}
	else
	{
		CharacterSpawnRotation = FRotator(0.f, 100.f, 0.f);
	}
	AShotNFallCharacter* Character = GetWorld()->SpawnActor<AShotNFallCharacter>(CharacterClass, CharacterSpawnLocation, CharacterSpawnRotation);

	CharactersPool.Push(Character);

	Character->OnFallen.AddDynamic(this, &AShotNFallGameMode::SetRespawnTimer);
	return Character;
}

void AShotNFallGameMode::SetRespawnTimer(AShotNFallCharacter* CharacterToRespawn)
{
	AController* CharacterController;
	if (CharacterToRespawn->IsPlayerControlled())
	{
		CharacterController = CharacterToRespawn->GetController();
	}
	else
	{
		CharacterController = GetWorld()->SpawnActor<ASNFAIController>(AIClass);
	}

	DeleteFromCharacterPool(CharacterToRespawn);

	OnFall.Broadcast(CharacterToRespawn);

	TArray<AActor*>AttachedActors;
	CharacterToRespawn->GetAttachedActors(AttachedActors);
	for (auto AttachedActor : AttachedActors)
	{
		AttachedActor->Destroy();
	}
	CharacterToRespawn->Destroy();

	FTimerHandle TimerHandle_RespawnTimer;
	FTimerDelegate RespawnDelegate = FTimerDelegate::CreateUObject(this, &AShotNFallGameMode::RespawnCharacter, CharacterController);
	GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, RespawnDelegate, RespawnTime, false);

}

void AShotNFallGameMode::RespawnCharacter(AController* ControllerToPossess)
{
	int32 RandomPlatformNumberToSpawn = FMath::RandRange(0, Platforms.Num() - 1);
	FVector SpawnLocation = Platforms[RandomPlatformNumberToSpawn]->GetActorLocation();
	AShotNFallCharacter* Character = SpawnCharacter(SpawnLocation, CharactersPool);
	ControllerToPossess->Possess(Character);
}

float AShotNFallGameMode::GetRespawnTime() const
{
	return RespawnTime;
}

TArray<AActor*> AShotNFallGameMode::GetAllSpawnedPlatforms() const
{
	return Platforms;
}

int32 AShotNFallGameMode::DeleteFromCharacterPool(AShotNFallCharacter * CharacterToDelete)
{
	int32 NumberToDelete;
	CharactersPool.Find(CharacterToDelete, NumberToDelete);
	CharactersPool.RemoveAt(NumberToDelete);
	return NumberToDelete;
}

void AShotNFallGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
