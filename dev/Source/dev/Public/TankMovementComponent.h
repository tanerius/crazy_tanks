// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Manages the fly by wire movement abstraction for the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DEV_API UTankMovementComponent : public UNavMovementComponent
{
    GENERATED_BODY()


private:
    UTankTrack* leftTrack = nullptr;
    UTankTrack* rightTrack = nullptr;
   
    UPROPERTY(EditDefaultsOnly)
    float maxSpeed = 1300.0f;
    UPROPERTY(EditDefaultsOnly)
    float minSpeed = -1000.0f;

public:
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialize(UTankTrack* leftToSet, UTankTrack* rightToSet);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void IntendMoveForward(float moveThrow);
    UFUNCTION(BlueprintCallable, Category = "Input")
    void IntendTurnLeftRight(float moveThrow);
	
};
