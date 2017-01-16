// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    // Get player and AI tank
    auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

    if (!ensure(playerTank)) { return; }
    
    // Move towards player
    MoveToActor(playerTank, acceptanceRadius);

    aimingComponent->DoAim(playerTank->GetActorLocation());
    aimingComponent->Fire();
        
    return;
}

