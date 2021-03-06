// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Derived from a UStaticMeshComponent used to apply forces to a tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class DEV_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
    UTankTrack();
    void ApplySidewaysForce();
    virtual void BeginPlay() override;
    void DriveTrack();

    float currentThrottle = 0.0f;

    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* hitComponent,
        AActor* otherActor,
        UPrimitiveComponent* otherHitComponent,
        FVector normalImpulse,
        const FHitResult& hit
    );
public:
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetThrottle(float throttle);
	
    // max force per track in newtons (400K Newtons)
    // 10m/s^2 * 40000kg ... F=m*a
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float maxTrackDrivingForce = 400000.0f; 
};
