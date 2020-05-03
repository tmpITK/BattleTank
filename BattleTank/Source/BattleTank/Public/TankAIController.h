// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <memory>

#include "ControllerAux.h"
#include "AIController.h"

#include "TankAIController.generated.h"
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

friend class ControllerAux;

private:
	std::unique_ptr<ControllerAux> ControllerHelper = std::make_unique<ControllerAux>();

	virtual void Tick(float DeltaTime) override;
};
