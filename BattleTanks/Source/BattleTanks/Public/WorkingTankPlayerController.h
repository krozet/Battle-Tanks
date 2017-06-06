// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WorkingTank.h"
#include "GameFramework/PlayerController.h"
#include "WorkingTankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API AWorkingTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AWorkingTank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
	
};
