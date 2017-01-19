#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


class UTankAimingComponent;

/**
 * AI Tank controller
 */
UCLASS()
class DEV_API ATankAIController : public AAIController
{
	GENERATED_BODY()
    
protected:
    UTankAimingComponent* aimingComponent = nullptr;

    // How close can an AI tank get to a player (assuming in centimetres)
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float acceptanceRadius = 8000.0f;

private:

    void BeginPlay() override;
	
    // override the tick method so we can use it for aiming towards the player
    virtual void Tick(float DeltaSeconds) override;
};
