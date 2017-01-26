// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::SetPawn(APawn* inPawn)
{
    Super::SetPawn(inPawn);
    if (inPawn)
    {
        auto possessedTank = Cast<ATank>(inPawn);
        if (!ensure(possessedTank)) { return; }
        // Now subscribe our local method to the tanks death method
        possessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
    }
}

void ATankAIController::OnPossessedTankDeath()
{
    if (!GetPawn()) { return; }
    GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    // Get player and AI tank
    auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

    if (!playerTank) { return; }
    
    // Move towards player
    EPathFollowingResult::Type x = MoveToActor(playerTank, acceptanceRadius);

    aimingComponent->DoAim(playerTank->GetActorLocation());

    // if aiming or locked then fire
    if (aimingComponent->GetFiringState() == EFiringStatus::Locked)
    {
        aimingComponent->Fire();
    }
        
    return;
}

