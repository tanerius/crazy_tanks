// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

void ATank::FireCannon()
{
    bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds;
    return;
    if (barrel && isReloaded) {
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

void ATank::SetBarrelReference(UTankBarrel* barrelToSet)
{
    tankAimingComponent->SetBarrelReference(barrelToSet);
    barrel = barrelToSet;
}

void ATank::SetTurretReference(UTurret* turretToSet)
{
    tankAimingComponent->SetTurretReference(turretToSet);
}

void ATank::AimAt(FVector hitLocation)
{
    tankAimingComponent->DoAim(hitLocation, launchSpeed);
    return;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}
