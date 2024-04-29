// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNode_SetStateAsPassive.h"
#include "AIController.h"
#include "Enemies/AI/AICEnemyBase.h"

EBTNodeResult::Type UBTTNode_SetStateAsPassive::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  AAICEnemyBase* AIController = Cast<AAICEnemyBase>(OwnerComp.GetAIOwner());
  if (!AIController)
    return EBTNodeResult::Failed;

  AIController->SetStateAsPassive();

  return EBTNodeResult::Succeeded;
}
