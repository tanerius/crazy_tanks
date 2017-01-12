// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    projectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
    projectileMoveComponent->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}


void AProjectile::LaunchProjectile(float speed)
{
    auto timeNow = GetWorld()->GetTimeSeconds();
    //UE_LOG(LogTemp, Warning, TEXT("%f: Firing the projectile!!! "), timeNow);
    projectileMoveComponent->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
    projectileMoveComponent->Activate(); // activate our projectile
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


