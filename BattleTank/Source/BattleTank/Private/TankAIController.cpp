// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AI_Id = GetName();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player %s found by AI %s"), *PlayerTank->GetName(), *AI_Id);
		return Cast<ATank>(PlayerTank);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI %s could not find player."), *AI_Id);
	}
	return nullptr;
}

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	ControllerHelper->LogPossession(*this, ControlledTank);

	auto PlayerTank = GetPlayerTank();

}
