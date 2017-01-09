// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class DEV_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
    void RotateTurret(float newAngle);

private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float maxDegreesPerSecond = 5.0f; // Sensible property
	
	
};
