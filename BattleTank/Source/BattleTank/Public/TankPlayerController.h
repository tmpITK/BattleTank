// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "Tank.h"
#include "ControllerAux.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	friend class ControllerAux;	
public:
	virtual void BeginPlay() override;
	
private:
	std::unique_ptr<ControllerAux> ControllerHelper = std::make_unique<ControllerAux>();

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5, CrosshairYLocation = 0.3333;

	ATank* GetControlledTank() const;

	virtual void Tick(float DeltaTime) override;

	//Move the barrel towards the crosshair
	void AimTowardsCrosshair();

	// True if hit landscape
	bool GetSightRayLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(const FVector2D& ScreenLocation, FVector& OutLookDirection) const;
};
