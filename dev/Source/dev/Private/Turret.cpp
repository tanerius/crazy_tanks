// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "Turret.h"


void UTurret::RotateTurret(float newRelativeYaw)
{


    //clamp the relativeSpeed between -1 and +1
    float relativeSpeedClamped = FMath::Clamp<float>(newRelativeYaw, -1, 1);
    // multiply by GetWorld()->DeltaTimeSeconds to correct frame rate differences
    auto yawChange = relativeSpeedClamped * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    // calculate new elevation without claming to max and min
    auto rawYaw = RelativeRotation.Yaw + yawChange;

    //auto timeNow = GetWorld()->GetTimeSeconds();
    //UE_LOG(LogTemp, Warning, TEXT("%f: Relative Yaw %f "), timeNow, newRelativeYaw);
    
    SetRelativeRotation(FRotator(0.0f, rawYaw, 0.0f));
    
    return;
}

