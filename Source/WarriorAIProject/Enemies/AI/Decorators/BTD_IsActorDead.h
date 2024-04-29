// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsActorDead.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API UBTD_IsActorDead : public UBTDecorator
{
	GENERATED_BODY()

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere, Category = "Actor")
	FBlackboardKeySelector ActorKey;
};
