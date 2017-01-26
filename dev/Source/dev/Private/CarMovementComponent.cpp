// Copyright Taner Selim 2016

#include "dev.h"
#include "Wheel.h"
#include "CarMovementComponent.h"


void UCarMovementComponent::Initialize(UWheel* leftToSet, UWheel* rightToSet)
{
    if (!ensure(leftToSet && rightToSet)) { return; }
    leftWheel = leftToSet;
    rightWheel = rightToSet;
}

void UCarMovementComponent::IntendMoveForward(float moveThrow)
{
    if (!ensure(leftWheel && rightWheel)) { return; }
    leftWheel->RotateWheel(moveThrow);
    rightWheel->RotateWheel(moveThrow);
    return;
}

void UCarMovementComponent::IntendTurn(float moveThrow)
{
    return;
}

void UCarMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    // No need to call super. Need to completely replace funcitonality of parent
    // Note: MoveVelocity is NOT a unit vector, but we're only interested in the direction
    
    auto carForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto aiForwardIntention = MoveVelocity.GetSafeNormal(); // where AI pathfinding would like to orient and move the car

                                                            // calculate the dot product
                                                            // A*B = ||A|| ||B|| cos(angle)
    float forwardThrow = FVector::DotProduct(carForward, aiForwardIntention);
    float rightThrow = FVector::CrossProduct(aiForwardIntention, carForward).Z;

    IntendMoveForward(forwardThrow);
    IntendTurn(rightThrow);
  
}