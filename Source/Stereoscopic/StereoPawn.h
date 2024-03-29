// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "StereoPawn.generated.h"

UCLASS()
class STEREOSCOPIC_API AStereoPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AStereoPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float val);

	void TriggerTour();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool bForward, bBackward;

};
