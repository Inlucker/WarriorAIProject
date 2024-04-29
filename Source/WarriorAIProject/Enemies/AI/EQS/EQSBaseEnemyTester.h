// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EQSTestingPawn.h"
#include "Enemies/EnemyBase.h"
#include "EQSBaseEnemyTester.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API AEQSBaseEnemyTester : public AEQSTestingPawn, public IEnemyBase
{
	GENERATED_BODY()

public:
	virtual FVector GetPatrolMidLocation() const override;

	virtual float SetMoveSpeed(EMoveSpeed speed) override;

	UPROPERTY(EditAnywhere, Category = "PatrolLocation")
	FVector PatrolLocation;
};
