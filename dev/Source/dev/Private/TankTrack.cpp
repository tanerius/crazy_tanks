// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float throttle)
{
    //auto timeNow = GetWorld()->GetTimeSeconds();
    auto name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *name, throttle);

    // TODO: Clamp actual throttle value so player can't overdrive
}