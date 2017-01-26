// Copyright Taner Selim 2016

#include "dev.h"
#include "Wheel.h"

void UWheel::RotateWheel(float relativeSpeed)
{
    //clamp the relativeSpeed between -1 and +1
    float relativeSpeedClamped = FMath::Clamp<float>(relativeSpeed, -1, 1);
    // multiply by GetWorld()->DeltaTimeSeconds to correct frame rate differences
    float max = maxSpeed;
    if (relativeSpeed < 0)
    {
        max = maxReverseSpeed;
    }
    auto pitchChange = relativeSpeedClamped * max * GetWorld()->DeltaTimeSeconds;
    // calculate new angle 
    auto rawPitch = RelativeRotation.Pitch + pitchChange;

    auto timeNow = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("%f: Relative Pitch %f "), timeNow, pitchChange);

    SetRelativeRotation(FRotator(rawPitch, 0.0f, 0.0f));

    return;
}

void UWheel::YawWheel(float relativeSpeed)
{
    return;
}


