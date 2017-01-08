// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEV_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

    void SetBarrelReference(UStaticMeshComponent* barrelToSet);

	// Called when the game starts
	virtual void BeginPlay() override;

    void DoAim(FVector targetLocation);
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
    // get a reference to the barrel of the tank
    UStaticMeshComponent* tankBarrel = nullptr;
	
};
