// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNode_EquipWeapon.h"
#include "AIController.h"
#include "../../../Components/WeaponComponent.h"


EBTNodeResult::Type UBTTNode_EquipWeapon::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
  _OwnerComp = &OwnerComp;
  APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UWeaponComponent* WeaponComp = Pawn->FindComponentByClass<UWeaponComponent>();
    if (WeaponComp)
    {
      if (WeaponComp->IsEquiped())
        return EBTNodeResult::Succeeded;
      WeaponComp->OnEquipFinished.AddDynamic(this, &UBTTNode_EquipWeapon::OnEquipFinished);
      WeaponComp->CallEquip();
      return EBTNodeResult::InProgress;
    }
  }
  return EBTNodeResult::Failed;
}

void UBTTNode_EquipWeapon::OnEquipFinished()
{
  APawn* Pawn = _OwnerComp->GetAIOwner()->GetPawn();
  if (Pawn)
  {
    UWeaponComponent* WeaponComp = Pawn->FindComponentByClass<UWeaponComponent>();
    if (WeaponComp)
      WeaponComp->OnEquipFinished.RemoveDynamic(this, &UBTTNode_EquipWeapon::OnEquipFinished);
  }
  this->FinishLatentTask(*_OwnerComp, EBTNodeResult::Succeeded);
}
