// Fill out your copyright notice in the Description page of Project Settings.


#include "AMuerteCharacter.h"

// Sets default values
AAMuerteCharacter::AAMuerteCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAMuerteCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAMuerteCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAMuerteCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

