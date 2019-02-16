// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
	ControllerHelper->LogPossession(*this);
}
