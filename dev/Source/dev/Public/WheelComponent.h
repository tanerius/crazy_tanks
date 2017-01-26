// Copyright Taner Selim 2016

#pragma once

#include "Components/ActorComponent.h"
#include "WheelComponent.generated.h"

class UWheel;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEV_API UWheelComponent : public UActorComponent
{
	GENERATED_BODY()

private:
    UWheel* leftWheel = nullptr;
    UWheel* rightWheel = nullptr;
public:	
	// Sets default values for this component's properties
	UWheelComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
