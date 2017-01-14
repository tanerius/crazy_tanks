// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


class ATank;

/**
 * 
 */
UCLASS()
class DEV_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
    // How close can an AI tank get to a player (assuming in centimetres)
    float acceptanceRadius = 500.0f;

    void BeginPlay() override;
	
    // override the tick method so we can use it for aiming towards the player
    virtual void Tick(float DeltaSeconds) override;
};
