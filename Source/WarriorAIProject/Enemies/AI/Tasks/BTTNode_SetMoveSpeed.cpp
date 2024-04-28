// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNode_SetMoveSpeed.h"
#include "AIController.h"

EBTNodeResult::Type UBTTNode_SetMoveSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
  if (Pawn)
  {
    if (Pawn->GetClass()->ImplementsInterface(UEnemyBase::StaticClass()))
    {
      IEnemyBase* baseEnemy = Cast<IEnemyBase>(Pawn);
      if (baseEnemy)
      {
        baseEnemy->SetMoveSpeed(newMoveSpeed);
        return EBTNodeResult::Succeeded;
      }
    }
  }
  return EBTNodeResult::Failed;
}
