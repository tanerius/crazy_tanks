// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet)
{
    tankBarrel = barrelToSet;
}

void UTankAimingComponent::DoAim(FVector targetLocation, float launchSpeed)
{
    if (!tankBarrel) { return; }

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
            ESuggestProjVelocityTraceOption::Type::DoNotTrace // trace option
        )
    )
    {
        // turn launch velocity vector into a unit vector
        auto aimDirection = outLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(aimDirection);
        auto timeNow = GetWorld()->GetTimeSeconds();
        UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found at %s"), timeNow, *aimDirection.ToString());
    }
    else
    {
        auto timeNow = GetWorld()->GetTimeSeconds();
        UE_LOG(LogTemp, Warning, TEXT("%f: No solution for aiming"), timeNow);
    }
   
    
}


void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
    // work out difference between currect barrel rotation and aim direction
    auto barrelRotator = tankBarrel->GetForwardVector().Rotation();
    auto aimAsRotator = aimDirection.Rotation();
    auto deltaRotator = aimAsRotator - barrelRotator;
    
    tankBarrel->Elevate(5); // TODO remove magic number

}

