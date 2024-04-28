// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsHPLessThan.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API UBTD_IsHPLessThan : public UBTDecorator
{
	GENERATED_BODY()

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere, Category = "HealthPercent")
	float healthPercent;	
};
