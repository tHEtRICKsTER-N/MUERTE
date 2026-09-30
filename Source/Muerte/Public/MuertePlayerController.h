// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MuertePlayerController.generated.h"

// Forward declarations
class UInputMappingContext;

UCLASS()
class MUERTE_API AMuertePlayerController : public APlayerController
{
	GENERATED_BODY()
	

private:
	// Input mapping context for the player controller
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
};
