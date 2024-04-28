// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ACompWithPriority.h"
#include "AttackComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackFinishedDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIORAIPROJECT_API UAttackComponent : public UACompWithPriority
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void CallAttack();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void CallAttackFinished();

public:
	UPROPERTY(BlueprintAssignable, Category = "Attack")
	FOnAttackDelegate OnAttack;

	UPROPERTY(BlueprintAssignable, Category = "Attack")
	FOnAttackFinishedDelegate OnAttackFinished;
};
