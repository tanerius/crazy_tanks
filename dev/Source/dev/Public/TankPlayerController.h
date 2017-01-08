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
private:
    // Start moving the tank barrel towards where the crosshair 
    // intersects the world - pretty complex stuff
    void AimTowardsCrosshair();

public:

    // Returns the Tank that is being possessed by this player controller.
    ATank* GetControlledTank() const;
	
    // virtual - allows other children to override
    virtual void BeginPlay() override;

    // override the tick method so we can use it for aiming towards the crosshair
    // virtual - allows other children to override
    virtual void Tick( float DeltaSeconds ) override;
};
