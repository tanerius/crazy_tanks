// Copyright Taner Selim 2016

#pragma once

#include "GameFramework/Pawn.h"
#include "Car.generated.h"

UCLASS()
class DEV_API ACar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
