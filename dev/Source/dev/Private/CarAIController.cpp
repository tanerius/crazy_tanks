// Copyright Taner Selim 2016

#include "dev.h"
#include "TankAimingComponent.h"
#include "CarAIController.h"


void ACarAIController::BeginPlay()
{
    Super::BeginPlay();
    //aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
    UE_LOG(LogTemp, Warning, TEXT("AI BeginPlay.. "));

    return;
}

void ACarAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!playerTank) { return; }
    MoveToActor(Cast<AActor>(playerTank), acceptanceRadius);
    return;
}