// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "ControllerAux.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

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

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;
	
private:
	std::unique_ptr<ControllerAux> ControllerHelper = std::make_unique<ControllerAux>();

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5, CrosshairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000; //10km in centimetres

	virtual void Tick(float DeltaTime) override;

	//Move the barrel towards the crosshair
	void AimTowardsCrosshair();

	// True if hit landscape
	bool GetSightRayLocation( FVector& OutHitLocation) const;

	bool GetLookDirection(const FVector2D& ScreenLocation, FVector& OutLookDirection) const;

	bool GetLookVectorHitLocation(const FVector& LookDirection, FVector & OutHitLocation) const;
};
