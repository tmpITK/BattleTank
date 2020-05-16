// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	auto AI_Id = GetName();
	if (ensure(PlayerTank && AimingComponent)) {
		//UE_LOG(LogTemp, Warning, TEXT("Player %s found by AI %s"), *PlayerTank->GetName(), *AI_Id);
		MoveToActor(PlayerTank, AcceptanceRadius);
		//Aim towards Player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		//AimingComponent->Fire();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI %s could not find player."), *AI_Id);
	}

}
