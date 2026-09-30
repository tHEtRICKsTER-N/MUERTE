// Fill out your copyright notice in the Description page of Project Settings.


#include "AMuerteCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"

// Sets default values
AMuerteCharacter::AMuerteCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creating the default subobjects
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	CameraBoom->SetupAttachment(RootComponent);
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);


	// Making sure the player and camera are independent
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;


	// Making sure that the character rotates in the direction of movement
	GetCharacterMovement()->bOrientRotationToMovement = true;


	// Making sure that the camera boom only rotates with the pawn and not the actual camera component
	CameraBoom->bUsePawnControlRotation = true;
	FollowCamera->bUsePawnControlRotation = false;
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

	// Setting up the Enhanced Input Component
	UInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInputComponent)
	{
		// Set the Inputs
		// Jump

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMuerteCharacter::Look);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMuerteCharacter::Move);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::StopJumping);
	}
	else {
		UE_LOG(LogInput, Warning, TEXT("Enhanced Input Component not found!"));
	}
}

void AMuerteCharacter::Move(const FInputActionValue& Value)
{
	
}

void AMuerteCharacter::Look(const FInputActionValue& Value)
{

}
