// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AMuerteCharacter.generated.h"

// Forward Declarations
class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class MUERTE_API AMuerteCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMuerteCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent> FollowCamera;

private:
	// Input Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> SprintAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> ADSAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;


	// Movement related variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = MovementSettings, meta = (AllowPrivateAccess = "true"))
	float WalkSpeed = 500.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = MovementSettings, meta = (AllowPrivateAccess = "true"))
	float SprintSpeed = 1000.f;


	// ADS Settings
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ADS, meta = (AllowPrivateAccess = "true"))
	float ADSSpeed = 10;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ADS, meta = (AllowPrivateAccess = "true"))
	FVector ADSOffset = FVector(0.f, 50.f, 15.f);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ADS, meta = (AllowPrivateAccess = "true"))
	float TargetArmLength = 200.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ADS, meta = (AllowPrivateAccess = "true"))
	bool bIsAiming;

	float DefaultTargetArmLength = 400.f;
	FVector DefaultSocketOffset = FVector::ZeroVector;


	// Functions
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartSprint(const FInputActionValue& Value);
	void StopSprint(const FInputActionValue& Value);
	void StartADS(const FInputActionValue& Value);
	void StopADS(const FInputActionValue& Value);
};
