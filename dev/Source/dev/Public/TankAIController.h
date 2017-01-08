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
	
    // Returns the Tank that is being possessed by this AI controller.
    ATank* GetControlledTank() const;

    void BeginPlay() override;
	
	
};
