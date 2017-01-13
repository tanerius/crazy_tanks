// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Derived from a UStaticMeshComponent used to apply forces to a tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class DEV_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = Input)
    void SetThrottle(float throttle);
	
	
};
