// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = false;

}

void UTankTrack::ApplySidewaysForce()
{
    //UE_LOG(LogTemp, Warning, TEXT("UTankTrack::TickComponent(...)  "));
    float deltaTime = GetWorld()->GetDeltaSeconds();
    // Calculate the slippage speed (sideways component) - use dot product
    auto slippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

    // calculate required acceleration this frame to correct
    auto correctionAccel = -slippageSpeed / deltaTime * GetRightVector();

    // calculate and apply sideways force F=ma
    // get the tank root
    auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    auto correctionForce = (tankRoot->GetMass() * correctionAccel) / 2; // /2 because 2 tracks
    tankRoot->AddForce(correctionForce);
}

void UTankTrack::BeginPlay()
{
    // UE_LOG(LogTemp, Warning, TEXT("UTankTrack::BeginPlay()  "));
    //Register an OnComponentHit handler funciton
    OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::DriveTrack()
{
    // Getting forward vector of the track
    auto forceApplied = GetForwardVector() * currentThrottle * maxTrackDrivingForce;
    // where to apply the force - the track location
    auto forceLocation = GetComponentLocation();
    // apply the force to the tank
    auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}

void UTankTrack::OnHit(
    UPrimitiveComponent* hitComponent,
    AActor* otherActor,
    UPrimitiveComponent* otherHitComponent,
    FVector normalImpulse,
    const FHitResult& hit)
{
    DriveTrack();
    ApplySidewaysForce();
    currentThrottle = 0.0f;
}

void UTankTrack::SetThrottle(float throttle)
{
    currentThrottle = FMath::Clamp<float>(currentThrottle + throttle, -1, 1);
    
}