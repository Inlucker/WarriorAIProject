// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/AI/EQS/EQSBaseEnemyTester.h"
#include "EQSBaseEnemyTester.h"

FVector AEQSBaseEnemyTester::GetPatrolMidLocation() const
{
  return PatrolLocation;
}

float AEQSBaseEnemyTester::SetMoveSpeed(EMoveSpeed speed)
{
  return 0.0f;
}
