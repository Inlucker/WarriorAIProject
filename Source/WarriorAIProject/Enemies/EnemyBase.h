// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyBase.generated.h"

UENUM(BlueprintType)
enum class EMoveSpeed : uint8
{
	Idle        UMETA(DisplayName = "Idle"),
	Walking     UMETA(DisplayName = "Walking"),
	Jogging     UMETA(DisplayName = "Jogging"),
	Sprinting   UMETA(DisplayName = "Sprinting")
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, NotBlueprintable)
class UEnemyBase : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class WARRIORAIPROJECT_API IEnemyBase
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, Category = "EnemyBase")
	virtual FVector GetPatrolMidLocation() const = 0;

	UFUNCTION(BlueprintCallable, Category = "EnemyBase")
	virtual float SetMoveSpeed(EMoveSpeed speed) = 0;
};
