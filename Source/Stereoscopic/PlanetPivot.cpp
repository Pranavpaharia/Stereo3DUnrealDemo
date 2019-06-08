// Fill out your copyright notice in the Description page of Project Settings.

#include "PlanetPivot.h"

// Sets default values
APlanetPivot::APlanetPivot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bCWStart = true;
	bCCWStart = false;
	bPlanetFound = false;
	

}



// Called when the game starts or when spawned
void APlanetPivot::BeginPlay()
{
	Super::BeginPlay();
	planetMesh = Cast<UStaticMeshComponent>(this->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	
	if (planetMesh != nullptr)
	{
		bPlanetFound = true;
		UE_LOG(LogTemp, Warning, TEXT("Got planet mesh"));
	}

	
	rotValue = 5.0f;

	timerCWDel.BindUFunction(this, FName("StartRotationClockWise"),rotValue);
	timerCCWDel.BindUFunction(this, FName("StartRotationCounterClockwise"), rotValue);
	//GetWorldTimerManager().SetTimer(fTimehandleCW, timerCWDel, 10.0f, true, 5.f);
	//GetWorldTimerManager().SetTimer(fTimehandleCCW, timerCCWDel, 10.0f, true, 1.f);
	stereoPawn = Cast<AStereoPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//GetWorldTimerManager().SetTimer(fTimehandle,this, &APlanetPivot::StartCCRotation, 10.0f, false,1.0f);
}



void APlanetPivot::StartRotationClockWise(float rValue)
{
	/*FRotator *rotator = new FRotator(0, 0, rValue);
	this->SetActorRotation(*rotator, ETeleportType::None);*/
	bCCWStart = false;
	bCWStart = true;
	UE_LOG(LogTemp, Warning, TEXT("Start Roatation Clockwise"));
}

void APlanetPivot::StartRotationCounterClockwise(float rValue)
{
	bCCWStart = true;
	bCWStart = false;
	UE_LOG(LogTemp, Warning, TEXT("Start Roatation Anti-Clockwise"));
}

void APlanetPivot::RotateBody(bool bfoward, bool bBackward)
{


	if(bfoward)
	{
		frotator = FRotator(0.0f, 0.5f, 0.0f);
		this->AddActorWorldRotation(frotator, false, nullptr, ETeleportType::None);
		
	}
	if (bBackward)
	{
		frotator = FRotator(0.0f, -0.8f, 0.0f);
		this->AddActorWorldRotation(frotator, false, nullptr, ETeleportType::None);
		UE_LOG(LogTemp, Warning, TEXT("Inside Rotation 2 function"));
	}
}

void APlanetPivot::StartPlanetTour()
{
	currentAngle = this->GetActorRotation().Yaw;

	if (currentAngle > 89.0f)
	{
		bCWStart = false;

	}

	if (bCWStart)
	{
		frotator = FRotator(0.0f, 0.5f, 0.0f);
		this->AddActorWorldRotation(frotator, false, nullptr, ETeleportType::None);
		FString floatStr = this->GetActorRotation().ToCompactString();
		UE_LOG(LogTemp, Warning, TEXT("Inside Rotation 2 function %s"), *floatStr);
	}
}


// Called every frame
void APlanetPivot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (stereoPawn != nullptr)
	{
		RotateBody(stereoPawn->bForward,stereoPawn->bBackward);
	}

	if (bPlanetFound)
	{
		frotator = FRotator(0, 0.2f, 0);
		planetMesh->AddLocalRotation(frotator, false);
	}

	//StartPlanetTour();
	


}

