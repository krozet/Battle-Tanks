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
	virtual void Tick( float DeltaTime ) override;
private:
	//Start the tank moving the barrel so that a show would hit where
	//the crosshairs intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
