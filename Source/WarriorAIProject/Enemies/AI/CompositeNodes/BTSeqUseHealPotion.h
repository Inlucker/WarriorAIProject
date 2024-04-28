// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Composites/BTComposite_Sequence.h"
#include "HasPriority.h"
#include "BTSeqUseHealPotion.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API UBTSeqUseHealPotion : public UBTComposite_Sequence, public IHasPriority
{
	GENERATED_BODY()

public:
	virtual int GetPriority(AAIController* OwnerComp) const override;
};
