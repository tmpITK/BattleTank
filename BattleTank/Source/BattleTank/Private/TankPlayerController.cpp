// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
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
		GetControlledTank()->AimAt(HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation:%s"), *HitLocation.ToString());
	}
	
	
}

bool ATankPlayerController::GetSightRayLocation(FVector & OutHitLocation) const
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation(ViewPortSizeX * CrosshairXLocation,
							ViewPortSizeY * CrosshairYLocation);


	FVector LookDirection;
	if(GetLookDirection(ScreenLocation, LookDirection))
	{
		
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(const FVector2D & ScreenLocation, FVector & OutLookDirection) const
{
	FVector WorldLocation;
	 return DeprojectScreenPositionToWorld(
		ScreenLocation.X, ScreenLocation.Y,
		WorldLocation, OutLookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(const FVector &LookDirection, FVector & OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		StartLocation, 
		EndLocation, 
		ECollisionChannel::ECC_Visibility
	)) 
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}




