// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNode_SetFocus.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTNode_SetFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  AAIController* AIController = OwnerComp.GetAIOwner();
  if (!AIController)
    return EBTNodeResult::Failed;

  UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
  if (!BlackboardComp)
    return EBTNodeResult::Failed;

  AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(focusTargetKey.SelectedKeyName));
  if (!TargetActor)
    return EBTNodeResult::Failed;

  AIController->SetFocus(TargetActor);

  return EBTNodeResult::Succeeded;
}
