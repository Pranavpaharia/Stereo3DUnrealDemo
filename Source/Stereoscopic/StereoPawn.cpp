// Fill out your copyright notice in the Description page of Project Settings.

#include "StereoPawn.h"

// Sets default values
AStereoPawn::AStereoPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AStereoPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStereoPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStereoPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AStereoPawn::MoveForward);
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AStereoPawn::TriggerTour);


}

void AStereoPawn::TriggerTour()
{
	
}

void AStereoPawn::MoveForward(float val)
{
	if (val < 0)
	{
		bForward = false;
		bBackward = true;
		UE_LOG(LogTemp, Warning, TEXT("Move Backward"));
	}
	else if (val > 0)
	{
		bForward = true;
		bBackward = false;
		UE_LOG(LogTemp, Warning, TEXT("Move Forward"));
	}
	else if (val == 0)
	{
		bForward = bBackward = false;
		//UE_LOG(LogTemp, Warning, TEXT("No movement"));
	}

}
