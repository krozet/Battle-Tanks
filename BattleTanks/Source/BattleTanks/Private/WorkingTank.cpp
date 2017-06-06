// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "WorkingTank.h"


// Sets default values
AWorkingTank::AWorkingTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorkingTank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorkingTank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AWorkingTank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

