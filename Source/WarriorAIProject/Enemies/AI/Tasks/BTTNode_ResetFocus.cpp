// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNode_ResetFocus.h"
#include "AIController.h"

EBTNodeResult::Type UBTTNode_ResetFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  AAIController* AIController = OwnerComp.GetAIOwner();
  if (!AIController)
    return EBTNodeResult::Failed;

  AIController->ClearFocus(EAIFocusPriority::Gameplay);

  return EBTNodeResult::Succeeded;
}
