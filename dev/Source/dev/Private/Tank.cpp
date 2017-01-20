// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage
(
    float DamageAmount,
    struct FDamageEvent const & DamageEvent,
    class AController * EventInstigator,
    AActor * DamageCauser
)
{
    int32 damagePoints = FPlatformMath::RoundToInt(DamageAmount);
    int32 damageToApply = FMath::Clamp<int32>(DamageAmount, 0, damagePoints);
    currentHealth -= damageToApply;
    if (currentHealth <= 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Tank has died"));
    }

    return damageToApply;
}