// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float throttle)
{
    //auto timeNow = GetWorld()->GetTimeSeconds();
    auto name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *name, throttle);

    // TODO: Clamp actual throttle value so player can't overdrive
    // Getting forward vector of the track
    auto forceApplied = GetForwardVector() * throttle * maxTrackDrivingForce;
    // where to apply the force - the track location
    auto forceLocation = GetComponentLocation();
    // apply the force to the tank
    auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}