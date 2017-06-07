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

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0; //10 km

	//Start the tank moving the barrel so that a show would hit where
	//the cross hairs intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
