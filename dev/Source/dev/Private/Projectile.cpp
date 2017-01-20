// Fill out your copyright notice in the Description page of Project Settings.

#include "dev.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
    collisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
    // set the collisionmesh as the root component
    SetRootComponent(collisionMesh);
    
    // This sets true for "Simulation generates hit events"  - a sensible default
    collisionMesh->SetNotifyRigidBodyCollision(true);
    collisionMesh->SetVisibility(false);
    
    launchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
    launchBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

    projectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
    projectileMoveComponent->bAutoActivate = false;

    impactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
    impactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    impactBlast->bAutoActivate = false;

    explosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
    //attach it to the collision mesh or it will spawn at 0,0,0 and wont travel when fired
    explosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}


// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
    collisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}


void AProjectile::LaunchProjectile(float speed)
{
    auto timeNow = GetWorld()->GetTimeSeconds();
    //UE_LOG(LogTemp, Warning, TEXT("%f: Firing the projectile!!! "), timeNow);
    projectileMoveComponent->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
    projectileMoveComponent->Activate(); // activate our projectile
}

void AProjectile::OnHit(
    UPrimitiveComponent* hitComponent,
    AActor* otherActor,
    UPrimitiveComponent* otherHitComponent,
    FVector normalImpulse,
    const FHitResult& hit)
{
    launchBlast->Deactivate();
    impactBlast->Activate();
    explosionForce->FireImpulse();

    SetRootComponent(impactBlast);
    collisionMesh->DestroyComponent();

    // Destroy projectiles
    FTimerHandle timerHnd;
    GetWorld()->GetTimerManager().SetTimer(timerHnd, this, &AProjectile::OnTimerExpire, DestroyDelay, false);
}


void AProjectile::OnTimerExpire()
{
    Destroy();
}