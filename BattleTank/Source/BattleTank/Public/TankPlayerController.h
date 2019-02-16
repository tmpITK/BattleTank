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
	ATank* GetControlledTank() const;
};
