// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Enemies/EnemyBase.h"
#include "BTTNode_SetMoveSpeed.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API UBTTNode_SetMoveSpeed : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	UPROPERTY(EditAnywhere, Category = "MoveSpeed")
	EMoveSpeed newMoveSpeed;
};
