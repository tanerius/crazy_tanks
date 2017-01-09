// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float relativeSpeed)
{
    // move the barrel the right amount this frame
    // given max elevation speed, and the frame time

    //clamp the relativeSpeed between -1 and +1
    float relativeSpeedClamped = FMath::Clamp<float>(relativeSpeed, -1, 1);
    // multiply by GetWorld()->DeltaTimeSeconds to correct frame rate differences
    auto elevationChange = relativeSpeedClamped * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    // calculate new elevation without claming to max and min
    auto rawNewElevation = RelativeRotation.Pitch + elevationChange;
    //do clamping
    auto newElevation = FMath::Clamp<float>(rawNewElevation, minElevationDegrees, maxElevationDegrees);
    SetRelativeRotation(FRotator(newElevation, 0, 0));
    return;
}


