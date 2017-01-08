// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankPlayerController.h"


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