// Copyright Taner Selim 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Wheel.generated.h"

/**
* Derived from a UStaticMeshComponent representing a wheel
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class DEV_API UWheel : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
    float currentYaw;

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float maxSpeed = 100.0f; // degrees per second
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float maxReverseSpeed = 20.0f; // degrees per second
public:
    void RotateWheel(float relativeSpeed);
    void YawWheel(float relativeSpeed);
};