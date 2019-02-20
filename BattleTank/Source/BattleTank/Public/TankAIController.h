// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <memory>

#include "Tank.h"
#include "ControllerAux.h"
#include "AIController.h"

#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

friend class ControllerAux;
public:
	
	virtual void BeginPlay() override;
	
private:
	std::unique_ptr<ControllerAux> ControllerHelper = std::make_unique<ControllerAux>();
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void Tick(float DeltaTime) override;
};
