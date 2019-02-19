// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	ControllerHelper->LogPossession(*this, ControlledTank);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;
	FVector HitLocation; // Out param
	if (GetSightRayLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation:%s"), *HitLocation.ToString());
	}
	
	
}

bool ATankPlayerController::GetSightRayLocation(FVector & OutHitLocation) const
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation(ViewPortSizeX * CrosshairXLocation,
							ViewPortSizeY * CrosshairYLocation);

	UE_LOG(LogTemp, Warning, TEXT("Crosshair X and Y: %s"), *ScreenLocation.ToString());
	
	return true;
}




