// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
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
  AAICEnemyBase();

  UFUNCTION(BlueprintCallable, Category = "State")
  void SetStateAsPassive();

  UFUNCTION(BlueprintCallable, Category = "State")
  void SetStateAsDead();

  UFUNCTION(BlueprintCallable, Category = "State")
  void SetStateAsAttacking(AActor* AttackTarget);

  UFUNCTION(BlueprintCallable, Category = "State")
  void SetStateAsInvestigating(FVector location);

  UFUNCTION(BlueprintCallable, Category = "State")
  EStateEnemyBase GetCurrentState();

protected:
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Perception")
  UAIPerceptionComponent* AIPerceptionComponent;

  UFUNCTION()
  void HandleSense(AActor* Actor, FAIStimulus Stimulus);
};
