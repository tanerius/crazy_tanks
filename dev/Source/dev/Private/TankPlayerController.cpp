// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankPlayerController.h"


void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank())
        return;

    // get world location through crosshair (linetrace)
    // If it hits landscape
        // Tell controlled tank to aim crosshair
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
