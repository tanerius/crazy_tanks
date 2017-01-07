// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class DEV_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    // Returns the Tank that is being possessed by this player controller.
    ATank* GetControlledTank() const;
	
	
};
