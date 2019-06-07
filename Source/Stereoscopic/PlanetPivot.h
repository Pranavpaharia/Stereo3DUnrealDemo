// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	FTimerHandle fTimeManager;
	FTimerDelegate timerDel;

	void StartRotation();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
