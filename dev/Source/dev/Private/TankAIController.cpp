// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    ATank* aiPlayer = Cast<ATank>(GetPawn());
    aiPlayer->isHuman = false;
    
    aimingComponent = aiPlayer->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    // Get player and AI tank
    ATank* playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    ATank* aiPlayer = Cast<ATank>(GetPawn());

    if (playerTank && aiPlayer)
    {
        // Move towards player
        MoveToActor(playerTank, acceptanceRadius);

        //aiPlayer->AimAt(playerTank->GetActorLocation());
        aimingComponent->DoAim(playerTank->GetActorLocation());
        aiPlayer->FireCannon(); 
    }
    
    return;
}

