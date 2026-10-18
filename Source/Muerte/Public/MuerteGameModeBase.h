// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MuerteGameModeBase.generated.h"

/**
 * Base GameMode for Muerte.
 * Authority only (runs on the server / listen server).
 */
UCLASS()
class MUERTE_API AMuerteGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMuerteGameModeBase();
};
