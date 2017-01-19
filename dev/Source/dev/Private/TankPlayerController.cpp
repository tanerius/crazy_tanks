// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"


void ATankPlayerController::AimTowardsCrosshair()
{

    FVector hitLocation; // Out parameter
    if (GetSightRayHitLocation(hitLocation)) {
        aimingComponent->DoAim(hitLocation);
    }
    
    return;
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
    if (ensure(aimingComponent))
    {
        FoundAimingComponent(aimingComponent);
    }
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const
{
    FVector cameraWorldLocation; // Discard this
    return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, lookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const
{
    FVector cameraPointLocation = PlayerCameraManager->GetCameraLocation();
    FHitResult hitResult;

    if (
            GetWorld()->LineTraceSingleByChannel
            (
                hitResult,
                cameraPointLocation,
                cameraPointLocation + lookDirection * lineTraceRangeCm,
                ECollisionChannel::ECC_Visibility // Saying hit anything thats visible 
            )
        )
    {
        hitLocation = hitResult.Location;
        return true;
    }
    hitLocation = FVector(0.0f);
    return false;
}

// If it hits landscape return true
bool ATankPlayerController::GetSightRayHitLocation(FVector& hl) const
{
    hl = FVector(1.0f); // will set all components
        
    // Find the crosshair position
    int32 viewportSizeX, viewportSizeY;
    GetViewportSize(viewportSizeX, viewportSizeY);
    FVector2D screenLocation = FVector2D( viewportSizeX * crosshairXLocation, viewportSizeY * crosshairYLocation );

    // De-project screen position of the hrosshair to a world direction
    FVector lookDirection;
    if ( GetLookDirection(screenLocation, lookDirection) )
    {
        // Line trace along that look direction and see what we hit (up to max range)
        return GetLookVectorHitLocation(lookDirection, hl);
    }
    return false;
}

//Tick
    // Super
    // Aim towards crosshair
void ATankPlayerController::Tick( float DeltaSeconds )
{
    Super::Tick( DeltaSeconds );
    AimTowardsCrosshair();
    // Check to see all is working
    return;
}
