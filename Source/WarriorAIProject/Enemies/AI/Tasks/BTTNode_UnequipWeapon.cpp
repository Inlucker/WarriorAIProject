// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNode_UnequipWeapon.h"
#include "AIController.h"
#include "Components/WeaponComponent.h"

EBTNodeResult::Type UBTTNode_UnequipWeapon::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  _OwnerComp = &OwnerComp;
  APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UWeaponComponent* WeaponComp = Pawn->FindComponentByClass<UWeaponComponent>();
    if (WeaponComp)
    {
      if (!WeaponComp->IsEquiped())
        return EBTNodeResult::Succeeded;
      WeaponComp->OnUnequipFinished.AddDynamic(this, &UBTTNode_UnequipWeapon::OnUnequipFinished);
      WeaponComp->CallUnequip();
      return EBTNodeResult::InProgress;
    }
  }
  return EBTNodeResult::Failed;
}

void UBTTNode_UnequipWeapon::OnUnequipFinished()
{
  APawn* Pawn = _OwnerComp->GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UWeaponComponent* WeaponComp = Pawn->FindComponentByClass<UWeaponComponent>();
    if (WeaponComp)
      WeaponComp->OnUnequipFinished.RemoveDynamic(this, &UBTTNode_UnequipWeapon::OnUnequipFinished);
  }
  this->FinishLatentTask(*_OwnerComp, EBTNodeResult::Succeeded);
}

