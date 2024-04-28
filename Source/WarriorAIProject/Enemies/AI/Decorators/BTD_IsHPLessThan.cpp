// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsHPLessThan.h"
#include "AIController.h"
#include "../../../Components/HealthComponent.h"

bool UBTD_IsHPLessThan::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
  APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UHealthComponent* HealthComponent = Pawn->FindComponentByClass<UHealthComponent>();
    if (HealthComponent)
      return ((HealthComponent->GetHealth() / HealthComponent->GetMaxHealth()) <= healthPercent);
  }
  return false;
}

