// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Composites/BTComposite_Selector.h"
#include "BTSelNodeByPriority.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API UBTSelNodeByPriority : public UBTComposite_Selector
{
	GENERATED_BODY()

public:
	virtual int32 GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const override;
};
