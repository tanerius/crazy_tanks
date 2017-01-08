// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* barrelToSet)
{
    tankBarrel = barrelToSet;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UTankAimingComponent::DoAim(FVector targetLocation, float launchSpeed)
{
    //auto barrelLocation = tankBarrel->GetComponentLocation().ToString();
    UE_LOG(
        LogTemp, 
        Warning, 
        TEXT("Firing at: %f"), 
        launchSpeed
    );
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

