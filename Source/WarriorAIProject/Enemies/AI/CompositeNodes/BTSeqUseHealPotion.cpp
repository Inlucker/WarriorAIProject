// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSeqUseHealPotion.h"
#include "../../../Components/HealPotionsComponent.h"

int UBTSeqUseHealPotion::GetPriority(AAIController* OwnerComp) const
{
  if (OwnerComp)
  {
    APawn* Pawn = OwnerComp->GetPawn();
    if (Pawn)
    {
      UHealPotionsComponent* HealthPotionsComp = Pawn->FindComponentByClass<UHealPotionsComponent>();
      if (HealthPotionsComp)
        return HealthPotionsComp->GetPriority();
    }
  }
  return -1;
}


