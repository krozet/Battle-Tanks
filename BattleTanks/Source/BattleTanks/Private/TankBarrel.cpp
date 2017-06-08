// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	//makes speed no greater than 100%
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);

	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel elev called at speed %f"), Time, RelativeSpeed)
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	//sets rotation, but clamps value so that it is inbetween min and max
	SetRelativeRotation(FRotator(FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees), 0, 0));

}

