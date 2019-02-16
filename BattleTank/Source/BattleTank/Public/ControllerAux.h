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

	template<typename T1, typename T2>
	void LogPossession(const T1 &controller, const T2* ControlledTank)
	{
		auto name = controller.GetName();
		if (ControlledTank) {
			UE_LOG(LogTemp, Warning, TEXT("Controller %s possessing %s."), *name, *ControlledTank->GetName());
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Controller %s does not possess anything."), *name);
		}
	}

};
