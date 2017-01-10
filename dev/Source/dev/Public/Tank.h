// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

class UTankBarrel; // Do a class forward declaration
class UTurret;
class UTankAimingComponent;

UCLASS()
class DEV_API ATank : public APawn
{
	GENERATED_BODY()

public:
    void AimAt(FVector hitLocation);

    // Make the following method be callable from blueprint
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* barrelToSet);

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurretReference(UTurret* turretToSet);

    UFUNCTION(BlueprintCallable, Category = Setup)
    void FireCannon();

protected:
    UTankAimingComponent* tankAimingComponent = nullptr;

private:
    UPROPERTY(EditAnywhere, Category = Firing)
    float launchSpeed = 4000.0f; // 1000 metres per second. TODO: find a sensible default

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
