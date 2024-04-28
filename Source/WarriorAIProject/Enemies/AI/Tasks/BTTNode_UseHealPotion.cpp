// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNode_UseHealPotion.h"
#include "AIController.h"
#include "../../../Components/HealPotionsComponent.h"

EBTNodeResult::Type UBTTNode_UseHealPotion::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  _OwnerComp = &OwnerComp;
  APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UHealPotionsComponent* HealthPotionComp = Pawn->FindComponentByClass<UHealPotionsComponent>();
    if (HealthPotionComp)
    {
      if (HealthPotionComp->GetPotionsAmount() > 0)
      {
        HealthPotionComp->OnUsePotionEnd.AddDynamic(this, &UBTTNode_UseHealPotion::OnUsePotionEnd);
        HealthPotionComp->OnUsePotionStart.Broadcast();
        return EBTNodeResult::InProgress;
      }
    }
  }
  return EBTNodeResult::Failed;
}

void UBTTNode_UseHealPotion::OnUsePotionEnd()
{
  APawn* Pawn = _OwnerComp->GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UHealPotionsComponent* HealthPotionComp = Pawn->FindComponentByClass<UHealPotionsComponent>();
    if (HealthPotionComp)
      HealthPotionComp->OnUsePotionEnd.RemoveDynamic(this, &UBTTNode_UseHealPotion::OnUsePotionEnd);
  }
  this->FinishLatentTask(*_OwnerComp, EBTNodeResult::Succeeded);
}


