// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialize(UTankTrack* leftToSet, UTankTrack* rightToSet)
{
    if (!leftToSet || !rightToSet) { return; }
    leftTrack = leftToSet;
    rightTrack = rightToSet;
}

void UTankMovementComponent::IntendMoveForward(float moveThrow)
{
    if (!leftTrack || !rightTrack) { return; }
    leftTrack->SetThrottle(moveThrow);
    rightTrack->SetThrottle(moveThrow);
}
void UTankMovementComponent::IntendTurnLeftRight(float moveThrow)
{
    if (!leftTrack || !rightTrack) { return; }
    leftTrack->SetThrottle(moveThrow);
    rightTrack->SetThrottle(-moveThrow);
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    // No need to call super. Need to completely replace funcitonality of parent
    auto tankName = GetOwner()->GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s: Vectoring to %s "), *tankName, *MoveVelocity.ToString());
}