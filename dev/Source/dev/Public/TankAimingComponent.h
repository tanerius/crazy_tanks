// Copyright Taner Selim

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
    Reloading,
    Aiming,
    Locked,
    Ammo
};

// Do a class forward declaration
class UTankBarrel; 
class UTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEV_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
    void DoAim(FVector targetLocation);
    
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialize(UTurret* turretToSet, UTankBarrel* barrelToSet);

    UFUNCTION(BlueprintCallable, Category = "Firing")
    void Fire();


    EFiringStatus GetFiringState() const;

    UFUNCTION(BlueprintCallable, Category = "Firing")
    int32 GetRoundsLeft() const;

protected:
    // Firing state
    UPROPERTY(BluePrintReadOnly, Category = "State")
    EFiringStatus firingStatus = EFiringStatus::Reloading;

    // get a reference to the barrel of the tank
    UPROPERTY(BluePrintReadOnly, Category = "Setup")
    UTankBarrel* tankBarrel = nullptr;
    // get a reference to the turret
    UPROPERTY(BluePrintReadOnly, Category = "Setup")
    UTurret* tankTurret = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float reloadTimeInSeconds = 3.0f; // sensible default

    int32 roundsLeft = 5;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float launchSpeed = 10000.0f;
    void MoveBarrelTowards(FVector aimDirection);
    float NormalizeAngle(float unrealAngle); // returns an angle from 0 - 360 degrees given an unreal engine angle
    double lastFireTime = 0;
    bool isBarrelMoving = false;

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<AProjectile> projectileBlueprint;

    virtual void BeginPlay() override;
    bool IsBarrelMoving();
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
};
