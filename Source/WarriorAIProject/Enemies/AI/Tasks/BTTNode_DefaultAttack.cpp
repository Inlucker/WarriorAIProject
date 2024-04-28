// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNode_DefaultAttack.h"
#include "AIController.h"
#include "../../../Components/AttackComponent.h"

EBTNodeResult::Type UBTTNode_DefaultAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  _OwnerComp = &OwnerComp;
  APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UAttackComponent* AttackComp = Pawn->FindComponentByClass<UAttackComponent>();
    if (AttackComp)
    {
      //baseEnemy->Attack();
      AttackComp->CallAttack();
      AttackComp->OnAttackFinished.AddDynamic(this, &UBTTNode_DefaultAttack::OnAttackFinished);
      return EBTNodeResult::InProgress;
    }
  }
  return EBTNodeResult::Failed;
}

void UBTTNode_DefaultAttack::OnAttackFinished()
{
  APawn* Pawn = _OwnerComp->GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UAttackComponent* AttackComp = Pawn->FindComponentByClass<UAttackComponent>();
    if (AttackComp)
      AttackComp->OnAttackFinished.RemoveDynamic(this, &UBTTNode_DefaultAttack::OnAttackFinished);
  }
  this->FinishLatentTask(*_OwnerComp, EBTNodeResult::Succeeded);
}
