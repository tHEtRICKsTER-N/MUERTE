// Fill out your copyright notice in the Description page of Project Settings.


#include "AMuerteCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMuerteCharacter::AMuerteCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creating the default subobjects
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	CameraBoom->SetupAttachment(RootComponent);
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
}

void AMuerteCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMuerteCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMuerteCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

