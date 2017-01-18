// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    
    //UE_LOG(LogTemp, Warning, TEXT("UTankTrack::TickComponent(...)  "));

    // Calculate the slippage speed (sideways component) - use dot product
    auto slippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

    // calculate required acceleration this frame to correct
    auto correctionAccel = -slippageSpeed / DeltaTime * GetRightVector();

    // calculate and apply sideways force F=ma
    // get the tank root
    auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    auto correctionForce = (tankRoot->GetMass() * correctionAccel) / 2; // /2 because 2 tracks
    tankRoot->AddForce(correctionForce);
}

void UTankTrack::SetThrottle(float throttle)
{

    // TODO: Clamp actual throttle value so player can't overdrive
    // Getting forward vector of the track
    auto forceApplied = GetForwardVector() * throttle * maxTrackDrivingForce;
    // where to apply the force - the track location
    auto forceLocation = GetComponentLocation();
    // apply the force to the tank
    auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}