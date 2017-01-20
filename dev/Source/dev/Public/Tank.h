// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

UCLASS()
class DEV_API ATank : public APawn
{
	GENERATED_BODY()

private:
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    int32 startingHealth = 100;

    UPROPERTY(VisibleAnywhere, Category = "Health")
    int32 currentHealth = startingHealth;
    
public:
    ATank();

    // Called by the engine when actor damage is dealt
    virtual float TakeDamage
    (
        float DamageAmount,
        struct FDamageEvent const & DamageEvent,
        class AController * EventInstigator,
        AActor * DamageCauser
    ) override;
};
