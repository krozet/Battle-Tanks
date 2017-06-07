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
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString())
	}
}


//Get world location of line trace through cross hair, true if hits landscape
bool AWorkingTankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	///Find cross hair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString())
	}

	return true;
}

bool AWorkingTankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}