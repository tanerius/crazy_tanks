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
    void AimTowardsPlayer();

    // Returns the Tank that is being possessed by this AI controller.
    ATank* GetControlledTank() const;

    bool GetEnemyPlayerLocation(FVector& enemyPlayerLocation) const;

    // We need a method like this so that the AI can fint the player and target him
    ATank* GetPlayerTank() const;

    void BeginPlay() override;
	
    // override the tick method so we can use it for aiming towards the player
    virtual void Tick(float DeltaSeconds) override;
};
