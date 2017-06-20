// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UWorkingTankTurret;

//Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UWorkingTankTurret* TurretToSet);

	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankBarrel* Barrel = nullptr;
	UWorkingTankTurret* Turret = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);
};
