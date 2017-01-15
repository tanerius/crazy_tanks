// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
    Reloading,
    Aiming,
    Locked
};

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

protected:
    // Firing state
    UPROPERTY(BluePrintReadOnly, Category = "State")
    EFiringStatus firingStatus = EFiringStatus::Reloading;

private:
    // get a reference to the barrel of the tank
    UTankBarrel* tankBarrel = nullptr;
    // get a reference to the turret
    UTurret* tankTurret = nullptr;

    void MoveBarrelTowards(FVector aimDirection);
    float NormalizeAngle(float unrealAngle); // returns an angle from 0 - 360 degrees given an unreal engine angle
	
};
