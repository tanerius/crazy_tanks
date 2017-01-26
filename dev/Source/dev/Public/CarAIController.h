// Copyright Taner Selim 2016

#pragma once

#include "AIController.h"
#include "CarAIController.generated.h"

//class UTankAimingComponent;

/**
* Car Tank controller
*/
UCLASS()
class DEV_API ACarAIController : public AAIController
{
	GENERATED_BODY()
protected:
    // UTankAimingComponent* aimingComponent = nullptr;

    // How close can an AI tank get to a player (assuming in centimetres)
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float acceptanceRadius = 3000.0f;

private:
    virtual void BeginPlay() override;

    // This method gets called by the engine when the pawn is possessed by the AI!
    // virtual void SetPawn(APawn* inPawn) override;

    // override the tick method so we can use it for aiming towards the player
    virtual void Tick(float DeltaSeconds) override;
	
	
};
