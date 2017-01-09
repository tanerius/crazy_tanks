// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class DEV_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void Elevate(float degreesPerSecond);
	
private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float maxDegreesPerSecond = 10.0f; // Sensible property

    UPROPERTY(EditAnywhere, Category = Setup)
    float maxElevationDegrees = 35.0f; // Sensible property
    
    UPROPERTY(EditAnywhere, Category = Setup)
    float minElevationDegrees = 0.0f; // Sensible property
};
