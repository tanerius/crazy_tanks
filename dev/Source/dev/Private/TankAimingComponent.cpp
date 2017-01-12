// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "Tank.h"
#include "TankBarrel.h"
#include "Turret.h"
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
    if (!barrelToSet) { return; }
    tankBarrel = barrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTurret* turretToSet)
{
    if (!turretToSet) { return; }
    tankTurret = turretToSet;
}

void UTankAimingComponent::DoAim(FVector targetLocation, float launchSpeed)
{
    if (!tankBarrel) { return; }
    if (!tankTurret) { return; }

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
    //else
    //{
    //    auto timeNow = GetWorld()->GetTimeSeconds();
    //    UE_LOG(LogTemp, Warning, TEXT("%f: No solution for aiming"), timeNow);
    //}
   
    
}


void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
    // work out difference between currect barrel rotation and aim direction
    auto barrelRotator = tankBarrel->GetForwardVector().Rotation(); // current state
    auto aimAsRotator = aimDirection.Rotation(); // where to aim
    
    float targetYaw = 0;
    float currentYaw = 0;

    
    auto deltaRotator = aimAsRotator - barrelRotator; // angle difference
    
    tankBarrel->Elevate(deltaRotator.Pitch);
    
    // Normalization of Yaw angles to human readable
    if(aimAsRotator.Yaw < 0 ){
        targetYaw = (180 + (180 + aimAsRotator.Yaw));
    }
    else{
        targetYaw = aimAsRotator.Yaw;
    }
    
    if(barrelRotator.Yaw < 0){
        currentYaw = 180 + (180 + barrelRotator.Yaw);
    }
    else{
        currentYaw = barrelRotator.Yaw;
    }
    
    float rawDifference = FMath::Abs(currentYaw-targetYaw);
    
    if(rawDifference > 180)
    {
        if(currentYaw>targetYaw)
        {
            tankTurret->RotateTurret(rawDifference);
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
    

    /*
    auto ownerTank = Cast<ATank>(GetOwner());
    if(ownerTank->isHuman)
        UE_LOG(LogTemp, Warning, TEXT("current %f ; currentN:  %f ; to: %f ; toN : %f"), barrelRotator.Yaw, currentYaw, aimAsRotator.Yaw, targetYaw );
    */
    
    // rotate the turret too
    

}

