// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class DEV_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void LaunchProjectile(float speed);

private:
    UProjectileMovementComponent* projectileMoveComponent = nullptr;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* collisionMesh = nullptr;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UParticleSystemComponent* launchBlast = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UParticleSystemComponent* impactBlast = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    URadialForceComponent* explosionForce = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float DestroyDelay = 5.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float damageAmount = 20.0f;

    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* hitComponent,
        AActor* otherActor,
        UPrimitiveComponent* otherHitComponent,
        FVector normalImpulse,
        const FHitResult& hit);

    void OnTimerExpire();

};
