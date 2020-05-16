// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	
	auto AI_Id = GetName();
	if (ensure(PlayerTank && AimingComponent)) {
		//UE_LOG(LogTemp, Warning, TEXT("Player %s found by AI %s"), *PlayerTank->GetName(), *AI_Id);
		MoveToActor(PlayerTank, AcceptanceRadius);
		//Aim towards Player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		//ControlledTank->Fire();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI %s could not find player."), *AI_Id);
	}

}
