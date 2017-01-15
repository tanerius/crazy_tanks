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
    if (!ensure(leftTrack && rightTrack)) { return; }
    leftTrack->SetThrottle(moveThrow);
    rightTrack->SetThrottle(moveThrow);
}
void UTankMovementComponent::IntendTurnLeftRight(float moveThrow)
{
    if (!ensure(leftTrack && rightTrack)) { return; }
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
    float forwardThrow = FVector::DotProduct(tankForward, aiForwardIntention);
    float rightThrow = FVector::CrossProduct(aiForwardIntention, tankForward).Z;

    IntendMoveForward(forwardThrow);
    IntendTurnLeftRight(rightThrow);
}