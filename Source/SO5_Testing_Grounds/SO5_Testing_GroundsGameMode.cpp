// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SO5_Testing_GroundsGameMode.h"
#include "SO5_Testing_GroundsHUD.h"
#include "SO5_Testing_GroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASO5_Testing_GroundsGameMode::ASO5_Testing_GroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASO5_Testing_GroundsHUD::StaticClass();
}
