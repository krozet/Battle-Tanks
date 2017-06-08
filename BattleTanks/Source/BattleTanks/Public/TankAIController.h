// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class AWorkingTank;

UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	virtual void Tick(float DeltaTime) override;

public:

	AWorkingTank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
	AWorkingTank* GetPlayerTank() const;
};
