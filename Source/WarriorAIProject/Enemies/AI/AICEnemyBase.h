// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AICEnemyBase.generated.h"

UENUM(BlueprintType)
enum class EStateEnemyBase : uint8
{
  Passive        UMETA(DisplayName = "Passive"),
  Attacking      UMETA(DisplayName = "Attacking"),
  Investigating  UMETA(DisplayName = "Investigating"),
  Dead           UMETA(DisplayName = "Dead"),
  Unknown        UMETA(DisplayName = "Unknown")
};

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API AAICEnemyBase : public AAIController
{
	GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "State")
  void SetStateAsPassive();

  UFUNCTION(BlueprintCallable, Category = "State")
  void SetStateAsDead();
};
