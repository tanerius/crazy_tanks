// Copyright Taner Selim

#include "dev.h"
#include "TankBarrel.h"
#include "Turret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}

void UTankAimingComponent::Initialize(UTurret* turretToSet, UTankBarrel* barrelToSet)
{
    if (!ensure(barrelToSet && turretToSet))
    {
        UE_LOG(LogTemp, Warning, TEXT("Cant set turret and barrel"));
        return; 
    }
    
    tankBarrel = barrelToSet;
    tankTurret = turretToSet;
}

void UTankAimingComponent::DoAim(FVector targetLocation)
{
    if (!ensure(tankBarrel && tankTurret)) { return; }

    FVector outLaunchVelocity; // an out parameter 
    FVector startLocation = tankBarrel->GetSocketLocation(FName("Projectile")); // already created a Projectile socket
    FCollisionResponseParams responseParam;
    TArray < AActor * > actorsToIgnore;
    // calculate the out launch velocity
    if (
        UGameplayStatics::SuggestProjectileVelocity
        (
            this, // world context object
            outLaunchVelocity,
            startLocation,
            targetLocation,
            launchSpeed,
            false,
            0.0f,
            0.0f,
            ESuggestProjVelocityTraceOption::DoNotTrace
        )
    )
    {
        // turn launch velocity vector into a unit vector
        auto aimDirection = outLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(aimDirection);
    }
    
}

void UTankAimingComponent::Fire()
{
    if (!ensure(tankBarrel && projectileBlueprint)) { return; }
    bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds;
    if (isReloaded) {
        // Spawn a projectile
        auto projectile = GetWorld()->SpawnActor<AProjectile>(
            projectileBlueprint,
            tankBarrel->GetSocketLocation(FName("Projectile")),
            tankBarrel->GetSocketRotation(FName("Projectile"))
            );

        projectile->LaunchProjectile(launchSpeed);
        lastFireTime = FPlatformTime::Seconds();
    }

    return;
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
    if (!ensure(tankBarrel && tankTurret)) { return; }
    // work out difference between currect barrel rotation and aim direction
    auto barrelRotator = tankBarrel->GetForwardVector().Rotation(); // current state
    auto aimAsRotator = aimDirection.Rotation(); // where to aim
    
    float targetYaw = NormalizeAngle(aimAsRotator.Yaw);
    float currentYaw = NormalizeAngle(barrelRotator.Yaw);

    auto deltaRotator = aimAsRotator - barrelRotator; // angle difference
    
   
    
    float rawDifference = FMath::Abs(currentYaw-targetYaw);
    // Elevate the tank barrel as much as needed
    tankBarrel->Elevate(deltaRotator.Pitch);

    // Adjust the turret yaw correctly by moving towards the shortest path to target yaw
    // Thanx: Jovica K. and Nikola K. for the help
    if( rawDifference > 180 )
    {
        if( currentYaw>targetYaw )
        {
            tankTurret->RotateTurret( rawDifference );
        }
        else
        {
            tankTurret->RotateTurret(-rawDifference);
        }
    }
    else
    {
        if(currentYaw>targetYaw)
        {
            tankTurret->RotateTurret(-rawDifference);
        }
        else
        {
            tankTurret->RotateTurret(rawDifference);
        }
    }
}

float UTankAimingComponent::NormalizeAngle(float unrealAngle)
{
    float normalAngle = 0;

    if (unrealAngle < 0) {
        normalAngle = 360 + unrealAngle;
    }
    else {
        normalAngle = unrealAngle;
    }
    return normalAngle;
}

