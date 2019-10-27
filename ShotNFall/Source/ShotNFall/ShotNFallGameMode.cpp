// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ShotNFallGameMode.h"
#include "ShotNFallCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShotNFallGameMode::AShotNFallGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Logic/BP_SNFCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
