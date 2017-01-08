// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("ATankAIController BeginPlay()"));

    ATank* possesedTank = GetControlledTank();
    if (!possesedTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI not possesing a tank!"));
    }
    //else
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("AI possesing %s"), *possesedTank->GetName());
    //}
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

