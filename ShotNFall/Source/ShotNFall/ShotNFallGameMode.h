// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShotNFallGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFall, AShotNFallCharacter*, FallenCharacter);

class ASNF_PlatformBuilder;
class ATriggerBox;
class AShotNFallCharacter;
class ASNFAIController;

UCLASS(minimalapi)
class AShotNFallGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AShotNFallGameMode();

	FOnFall OnFall;

	TArray<AShotNFallCharacter*> GetCharacterPool();
	
	UFUNCTION()
	void SetRespawnTimer(AShotNFallCharacter*  CharacterToRespawn);

	void RespawnCharacter(AController* ControllerToPossess);

	float GetRespawnTime() const;

	TArray<AActor*> GetAllSpawnedPlatforms() const;

	int32 DeleteFromCharacterPool(AShotNFallCharacter* CharacterToDelete);

protected:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	AShotNFallCharacter* SpawnCharacter(const FVector& PlatformLocation, TArray<AShotNFallCharacter*>& CharactersPool);

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<ASNF_PlatformBuilder>LevelBuilderClass;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AShotNFallCharacter>CharacterClass;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<ASNFAIController>AIClass;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FVector CenterLevelLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 NumberOfBots;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float RespawnTime;

	UPROPERTY()
	TArray<AActor*>Platforms;

	UPROPERTY()
	TArray<AShotNFallCharacter*>CharactersPool;

private:

	FVector CharacterSpawnVerticalLocation;

};



