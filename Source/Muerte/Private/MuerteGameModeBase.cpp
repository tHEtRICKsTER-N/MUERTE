// Fill out your copyright notice in the Description page of Project Settings.

#include "MuerteGameModeBase.h"
#include "AMuerteCharacter.h"
#include "MuertePlayerController.h"

AMuerteGameModeBase::AMuerteGameModeBase()
{
	// Set default player controller class
	PlayerControllerClass = AMuertePlayerController::StaticClass();

	// Set default pawn class
	DefaultPawnClass = AMuerteCharacter::StaticClass();
}
