// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAM415_GonzalezGameMode.h"
#include "GAM415_GonzalezCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAM415_GonzalezGameMode::AGAM415_GonzalezGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
