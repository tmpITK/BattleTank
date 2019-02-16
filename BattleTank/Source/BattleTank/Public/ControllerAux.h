// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class BATTLETANK_API ControllerAux
{
public:
	ControllerAux();
	~ControllerAux();

	template<typename T>
	void LogPossession(const T &player)
	{
		auto name = player.GetName();
		UE_LOG(LogTemp, Warning, TEXT("Controller %s begin play."), *name);
		auto ControlledTank = player.GetControlledTank();
		if (ControlledTank) {
			UE_LOG(LogTemp, Warning, TEXT("Controller %s possessing %s."), *name, *ControlledTank->GetName());
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Controller %s does not possess anything."), *name);
		}
	}
};
