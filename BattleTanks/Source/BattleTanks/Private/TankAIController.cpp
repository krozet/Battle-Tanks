// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController %s is being possessed."), *ControlledTank->GetName())
	}
}

AWorkingTank* ATankAIController::GetControlledTank() const
{
	return Cast<AWorkingTank>(GetPawn());
}


