// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float degreesPerSecond)
{
    // move the barrel the right amount this frame
    // given max elevation speed, and the frame time

    UE_LOG(LogTemp, Warning, TEXT("Barrel elevate called at speed %f"), degreesPerSecond);
    return;
}


