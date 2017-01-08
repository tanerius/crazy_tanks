// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class DEV_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
    // Returns the Tank that is being possessed by this AI controller.
    ATank* GetControlledTank() const;

    // We need a method like this so that the AI can fint the player and target him
    ATank* GetPlayerTank() const;

    void BeginPlay() override;
	
	
};
