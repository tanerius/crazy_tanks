// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::FireCannon()
{
    if (!ensure(barrel)) { return; }
    bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds;
    return; // TODO: REMOVE THIS TO ENABLE TANKS TO FIRE
    if (isReloaded) {
        // Spawn a projectile
        auto projectile = GetWorld()->SpawnActor<AProjectile>(
            projectileBlueprint,
            barrel->GetSocketLocation(FName("Projectile")),
            barrel->GetSocketRotation(FName("Projectile"))
            );

        projectile->LaunchProjectile(launchSpeed);
        lastFireTime = FPlatformTime::Seconds();
    }
     
    return;
}

void ATank::BeginPlay()
{
    Super::BeginPlay(); // Needed for the BP BeginPlay event to be fired!
    tankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}
