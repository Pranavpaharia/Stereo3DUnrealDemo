// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StereoPawn.h"
#include "PlanetPivot.generated.h"



UCLASS()
class STEREOSCOPIC_API APlanetPivot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanetPivot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimerHandle fTimehandleCW;
	FTimerHandle fTimehandleCCW;

	AStereoPawn* stereoPawn;

	FTimerDelegate timerCCWDel;
	FTimerDelegate timerCWDel;

	float rotValue;
	FRotator frotator;
	UFUNCTION()
	void StartRotationClockWise(float rValue);

	UFUNCTION()
	void StartRotationCounterClockwise(float rValue);

	UFUNCTION()
	void RotateBody(bool bfoward,bool bBackward);


	UStaticMeshComponent *planetMesh;

	void StartPlanetTour();

	float currentAngle = 0.0f;

	bool bCWStart;
	bool bCCWStart;
	bool bPlanetFound;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
