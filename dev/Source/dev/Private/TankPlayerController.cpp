// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankPlayerController.h"


void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank())
        return;

    FVector hitLocation; // Out parameter
    if (GetSightRayHitLocation(hitLocation)) {
        UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *hitLocation.ToString());

        // Tell controlled tank to aim crosshair
    }

    
    return;
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("PleyerController BeginPlay()"));

    ATank* possesedTank = GetControlledTank();
    if (!possesedTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Not possesing a tank!"));
    }
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

// If it hits landscape return true
bool ATankPlayerController::GetSightRayHitLocation(FVector& hl) const
{
    hl = FVector(1.0f); // will set all components
    return true;
}

//Tick
    // Super
    // Aim towards crosshair
void ATankPlayerController::Tick( float DeltaSeconds )
{
    Super::Tick( DeltaSeconds );
    AimTowardsCrosshair();
    // Check to see all is working
    //UE_LOG(LogTemp, Warning, TEXT("Ticking from ATankPlayerController"));
    return;
}
