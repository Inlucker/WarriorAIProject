// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsUnequipping.h"
#include "AIController.h"
#include "../../../Components/WeaponComponent.h"

bool UBTD_IsUnequipping::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
  APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UWeaponComponent* WeaponComp = Pawn->FindComponentByClass<UWeaponComponent>();
    if (WeaponComp)
      return WeaponComp->IsUnequipping();
  }
  return false;
}
