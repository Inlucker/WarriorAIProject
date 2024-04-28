// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIORAIPROJECT_API UAttackComponent : public UActorComponent
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

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackDelegate);
	UPROPERTY(BlueprintAssignable, Category = "Attack")
	FOnAttackDelegate OnAttack;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackFinishedDelegate);
	UPROPERTY(BlueprintAssignable, Category = "Attack")
	FOnAttackFinishedDelegate OnAttackFinished;
};
