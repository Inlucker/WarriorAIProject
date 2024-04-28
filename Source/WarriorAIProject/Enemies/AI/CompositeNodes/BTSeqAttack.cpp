// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSeqAttack.h"
#include "../../../Components/AttackComponent.h"

int UBTSeqAttack::GetPriority(AAIController* OwnerComp) const
{
  APawn* Pawn = OwnerComp->GetPawn();
  if (Pawn)
  {
    UAttackComponent* AttackComp = Pawn->FindComponentByClass<UAttackComponent>();
    if (AttackComp)
    {
      return AttackComp->GetPriority();
    }
  }
  return -1;
}

