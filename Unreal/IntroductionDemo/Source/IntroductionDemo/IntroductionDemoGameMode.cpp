// Copyright Epic Games, Inc. All Rights Reserved.

#include "IntroductionDemoGameMode.h"
#include "IntroductionDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIntroductionDemoGameMode::AIntroductionDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
