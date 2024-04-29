// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/AI/EQS/EQCPatrolLocation.h"
#include "Enemies/EnemyBase.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Point.h"
#include "Engine/World.h"

void UEQCPatrolLocation::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
  AActor* QuerierActor = Cast<AActor>(QueryInstance.Owner.Get());
  if (QuerierActor)
  {
    IEnemyBase* EnemyBaseInterface = Cast<IEnemyBase>(QuerierActor);
    if (EnemyBaseInterface)
    {
      FVector PatrolLocation = EnemyBaseInterface->GetPatrolMidLocation();
      UEnvQueryItemType_Point::SetContextHelper(ContextData, PatrolLocation);
    }
  }
}
