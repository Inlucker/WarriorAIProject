// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.h"
#include "../Components/HealthComponent.h"
#include "../Components/AttackComponent.h"
#include "WarriorCharacter.generated.h"

UCLASS()
class WARRIORAIPROJECT_API AWarriorCharacter : public ACharacter, public IEnemyBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FVector GetPatrolMidLocation() const override;

	virtual float SetMoveSpeed(EMoveSpeed speed) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack", meta = (AllowPrivateAccess = "true"))
	UAttackComponent* AttackComponent;

private:
	FVector startPos;
};
