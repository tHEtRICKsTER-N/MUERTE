// Fill out your copyright notice in the Description page of Project Settings.


#include "AMuerteCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Muerte/Muerte.h"

// Sets default values
AMuerteCharacter::AMuerteCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

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
	
	// Applying the Input Mapping Context to the PlayerController
	if (APlayerController *MyController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(MyController->GetLocalPlayer()))
		{
			if(DefaultMappingContext)
				Subsystem->AddMappingContext(DefaultMappingContext,0);
		}
	}
}

void AMuerteCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMuerteCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Setting up the Enhanced Input Component
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Set the Inputs
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMuerteCharacter::Look);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMuerteCharacter::Move);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	}
	else {
		UE_LOG(LogMuerte, Warning, TEXT("Enhanced Input Component not found!"));
	}
}

void AMuerteCharacter::Move(const FInputActionValue& Value)
{
	// Take the value
	const FVector2D dir = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		// Take the direction of the Controller
		const FRotator rot = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, rot.Yaw,0.f);
		
		// Take the directions from the rotation
		const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		// Add the movement input in that direction
		AddMovementInput(ForwardDir,dir.Y);
		AddMovementInput(RightDir,dir.X);
	}
}

void AMuerteCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D dir = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		AddControllerYawInput(dir.X);
		AddControllerPitchInput(dir.Y);
	}
}
