// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/AI/Decorators/BTD_IsActorDead.h"
#include "AIController.h"
#include "Components/HealthComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UBTD_IsActorDead::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
  UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
  if (!BlackboardComp)
    return EBTNodeResult::Failed;

  AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(ActorKey.SelectedKeyName));
  if (!TargetActor)
    return EBTNodeResult::Failed;

  UHealthComponent* HealthComponent = TargetActor->FindComponentByClass<UHealthComponent>();
  if (HealthComponent)
    return HealthComponent->IsDead();

  return false;
}
