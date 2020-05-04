// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float NewThrottle)
{

	UE_LOG(LogTemp, Warning, TEXT("Throttle %f"), NewThrottle);

	auto ForceApplied = GetForwardVector() * NewThrottle * TrackMaximumFocre;
	auto ForceLocation = GetComponentLocation();
	//Root does not have physics component, have to upcast
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
