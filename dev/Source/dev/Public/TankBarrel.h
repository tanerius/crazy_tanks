// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class DEV_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void Elevate(float relativeSpeed);
	
private:
    UPROPERTY(EditAnywhere, Category = "Setup")
    float maxDegreesPerSecond = 10.0f; // Sensible property

    UPROPERTY(EditAnywhere, Category = "Setup")
    float maxElevationDegrees = 40.0f; // Sensible property
    
    UPROPERTY(EditAnywhere, Category = "Setup")
    float minElevationDegrees = 0.0f; // Sensible property
};
