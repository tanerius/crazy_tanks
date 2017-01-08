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

    ATank* thePlayer = GetPlayerTank();
    if(!thePlayer)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI doesnt see player"));
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!playerPawn) { return nullptr; }

    return Cast<ATank>(playerPawn);
}

