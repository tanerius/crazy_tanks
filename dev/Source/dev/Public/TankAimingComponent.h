// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Do a class forward declaration

class UTankBarrel; 
class UTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEV_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
    void DoAim(FVector targetLocation, float launchSpeed);
    void SetBarrelReference(UTankBarrel* barrelToSet);
    void SetTurretReference(UTurret* turretToSet);

private:
    // get a reference to the barrel of the tank
    UTankBarrel* tankBarrel = nullptr;
    // get a reference to the turret
    UTurret* tankTurret = nullptr;

    void MoveBarrelTowards(FVector aimDirection);
	
};
