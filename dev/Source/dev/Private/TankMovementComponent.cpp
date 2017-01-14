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
    // Note: MoveVelocity is NOT a unit vector, but we're only interested in the direction
    auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto aiForwardIntention = MoveVelocity.GetSafeNormal(); // where AI pathfinding would like to orient and move the tank

    // calculate the dot product
    // A*B = ||A|| ||B|| cos(angle)
    float moveThrow = FVector::DotProduct(tankForward, aiForwardIntention);
    IntendMoveForward(moveThrow);

    //UE_LOG(LogTemp, Warning, TEXT("%s: Vectoring to %s "), *tankName, *moveDirectionNormal.ToString());
}