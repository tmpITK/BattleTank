// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable, Category=Input)
	void SetThrottle(float NewThrottle);

	// Max force per track in Newton
	UPROPERTY(EditDefaultsOnly)
		float TrackMaximumFocre = 200000.0f; //0.5 g acceleration

};
