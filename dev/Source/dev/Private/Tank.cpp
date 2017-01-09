// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

void ATank::SetBarrelReference(UTankBarrel* barrelToSet)
{
    tankAimingComponent->SetBarrelReference(barrelToSet);
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
