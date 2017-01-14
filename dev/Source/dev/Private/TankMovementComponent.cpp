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
