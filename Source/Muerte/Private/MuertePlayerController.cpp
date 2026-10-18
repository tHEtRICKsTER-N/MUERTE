// Fill out your copyright notice in the Description page of Project Settings.


#include "MuertePlayerController.h"
#include "EnhancedInputSubsystems.h"

void AMuertePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Add input mapping context for local players
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultMappingContext)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}


