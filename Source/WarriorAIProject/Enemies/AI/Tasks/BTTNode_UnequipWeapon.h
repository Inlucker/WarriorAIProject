// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTNode_UnequipWeapon.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API UBTTNode_UnequipWeapon : public UBTTaskNode
{
	GENERATED_BODY()

  virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

  UBehaviorTreeComponent* _OwnerComp;
  UFUNCTION()
  void OnUnequipFinished();
	
};
