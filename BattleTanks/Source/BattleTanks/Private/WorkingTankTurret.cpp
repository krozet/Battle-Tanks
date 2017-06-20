// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "WorkingTankTurret.h"


void UWorkingTankTurret::Rotate(float RelativeSpeed)
{
	//makes speed no greater than 100%
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);

	//UE_LOG(LogTemp, Warning, TEXT("%f: Turret elev called at speed %f"), Time, RelativeSpeed)
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	//sets rotation, but clamps value so that it is inbetween min and max
	SetRelativeRotation(FRotator(0, Rotation, 0));

}

