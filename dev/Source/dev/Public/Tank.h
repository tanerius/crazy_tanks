// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

class UTankBarrel; // Do a class forward declaration
class AProjectile;

UCLASS()
class DEV_API ATank : public APawn
{
	GENERATED_BODY()
private:
    ATank();
};
