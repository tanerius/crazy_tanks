// Copyright Taner Selim 2016

#pragma once


#include "GameFramework/NavMovementComponent.h"
#include "CarMovementComponent.generated.h"

class UWheel;


/**
* Manages the fly by wire movement abstraction for the car
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DEV_API UCarMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
private:
    UWheel* leftWheel = nullptr;
    UWheel* rightWheel = nullptr;

    // Call by the pathfinding logic by the AI controllers
    virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
public:

    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialize(UWheel* leftToSet, UWheel* rightToSet);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void IntendMoveForward(float moveThrow);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void IntendTurn(float moveThrow);

};
