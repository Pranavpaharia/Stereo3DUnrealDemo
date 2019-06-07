// Fill out your copyright notice in the Description page of Project Settings.

#include "PlanetPivot.h"

// Sets default values
APlanetPivot::APlanetPivot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlanetPivot::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(fTimeManager, timerDel, 10, true, -1.f);
}

void APlanetPivot::StartRotation()
{
}

// Called every frame
void APlanetPivot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

