// Copyright Epic Games, Inc. All Rights Reserved.

#include "WarriorAIProjectGameMode.h"
#include "WarriorAIProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWarriorAIProjectGameMode::AWarriorAIProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Player/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
