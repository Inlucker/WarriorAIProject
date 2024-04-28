// Fill out your copyright notice in the Description page of Project Settings.


#include "AICEnemyBase.h"
#include "BehaviorTree/BlackboardComponent.h"

void AAICEnemyBase::SetStateAsPassive()
{
  UBlackboardComponent* blackBoard = GetBlackboardComponent();
  if (!blackBoard) return;
  blackBoard->SetValueAsEnum(FName(TEXT("State")), static_cast<uint8>(EStateEnemyBase::Passive));
}

void AAICEnemyBase::SetStateAsDead()
{
  UBlackboardComponent* blackBoard = GetBlackboardComponent();
  if (!blackBoard) return;
  blackBoard->SetValueAsEnum(FName(TEXT("State")), static_cast<uint8>(EStateEnemyBase::Dead));
}
