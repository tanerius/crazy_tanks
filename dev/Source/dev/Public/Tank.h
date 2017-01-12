// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

class UTankBarrel; // Do a class forward declaration
class UTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class DEV_API ATank : public APawn
{
	GENERATED_BODY()

public:
    bool isHuman = true;
    void AimAt(FVector hitLocation);

    // Make the following method be callable from blueprint
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void FireCannon();
    
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void SetBarrelReference(UTankBarrel* barrelToSet);

    UFUNCTION(BlueprintCallable, Category = "Setup")
    void SetTurretReference(UTurret* turretToSet);

protected:
    UTankAimingComponent* tankAimingComponent = nullptr;

private:
    /////////////////////////////////
    // PROPERTIES
    /////////////////////////////////
    
    UTankBarrel* barrel = nullptr;
    
    double lastFireTime = 0;
    // EditDefaultsOnly - can only change value inside Blueprint fo all instances
    // EditAnywhere - can chenge value for a particular instance
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float launchSpeed = 4000.0f; // 1000 metres per second.
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<AProjectile> projectileBlueprint;
    
    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float reloadTimeInSeconds = 3.0f; // sensible default
    
    

    
    /////////////////////////////////
    // MEMBERS
    /////////////////////////////////
    
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
