// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "WorkingTankPlayerController.h"

void AWorkingTankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController %s is being possessed."), *ControlledTank->GetName())
	}
}


void AWorkingTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

AWorkingTank* AWorkingTankPlayerController::GetControlledTank() const
{
	return Cast<AWorkingTank>(GetPawn());
}

void AWorkingTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//Out parameter
	FVector HitLocation;

	///Has "side effect", is going to line trace
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
	}
}


//Get world location of linetrace through crosshair, true if hits landscape
bool AWorkingTankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}
