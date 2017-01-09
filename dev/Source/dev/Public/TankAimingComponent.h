// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Do a class forward declaration

class UTankBarrel; 

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEV_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

    void SetBarrelReference(UTankBarrel* barrelToSet);

    // TODO: Add SetTurretReference

    void DoAim(FVector targetLocation, float launchSpeed);

private:
    // get a reference to the barrel of the tank
    UTankBarrel* tankBarrel = nullptr;
    void MoveBarrelTowards(FVector aimDirection);
	
};
