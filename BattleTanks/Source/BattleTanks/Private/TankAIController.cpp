// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetControlledTank();

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find a player tank."))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s."), *PlayerTank->GetName())
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

AWorkingTank* ATankAIController::GetControlledTank() const
{
	return Cast<AWorkingTank>(GetPawn());
}

AWorkingTank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<AWorkingTank>(PlayerPawn);
}

