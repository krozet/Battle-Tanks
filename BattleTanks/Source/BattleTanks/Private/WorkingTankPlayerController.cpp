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

AWorkingTank* AWorkingTankPlayerController::GetControlledTank() const
{
	return Cast<AWorkingTank>(GetPawn());
}


