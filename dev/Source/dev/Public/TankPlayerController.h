// Copyright Taner Selim

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include


class ATank;
class UTankAimingComponent;

/**
* Responsible for helping the player to aim
*/
UCLASS()
class DEV_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
    /////////////////////////////////
    // PROPERTIES
    /////////////////////////////////

    UPROPERTY(EditAnywhere)
    float crosshairXLocation = 0.5f;

    UPROPERTY(EditAnywhere)
    float crosshairYLocation = 0.33333f;

    UPROPERTY(EditAnywhere)
    float lineTraceRangeCm = 1000000.0f;

    
    /////////////////////////////////
    // MEMBERS
    /////////////////////////////////

    // Start moving the tank barrel towards where the crosshair 
    // intersects the world - pretty complex stuff
    void AimTowardsCrosshair();

    // virtual - allows other children to override
    virtual void BeginPlay() override;

    bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;
    bool GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;
    bool GetSightRayHitLocation(FVector& hl) const;

    // override the tick method so we can use it for aiming towards the crosshair
    // virtual - allows other children to override
    virtual void Tick( float DeltaSeconds ) override;

protected:
    // Returns the Tank that is being possessed by this player controller.
    UFUNCTION(BlueprintCallable, Category = "Setup")
    ATank* GetControlledTank() const;
    
    UTankAimingComponent* aimingComponent = nullptr;

    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void FoundAimingComponent(UTankAimingComponent* aimingCompRef);
};
