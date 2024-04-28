// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealPotionsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUsePotionStartDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUsePotionEndDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIORAIPROJECT_API UHealPotionsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealPotionsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Potions")
	int GetPotionsAmount();

	UFUNCTION(BlueprintCallable, Category = "Potions")
	int AddPotions(int addPotionsAmount);

	UFUNCTION(BlueprintCallable, Category = "Potions")
	int UsePotion();

	UFUNCTION(BlueprintCallable, Category = "Potions")
	void CallUsePotionStart();

	UFUNCTION(BlueprintCallable, Category = "Potions")
	void CallUsePotionEnd();

public:
	UPROPERTY(BlueprintAssignable, Category = "Potions")
	FOnUsePotionStartDelegate OnUsePotionStart;

	UPROPERTY(BlueprintAssignable, Category = "Potions")
	FOnUsePotionEndDelegate OnUsePotionEnd;

protected:
	UPROPERTY(EditAnywhere, Category = "Potions")
	int potionsAmount;

	UPROPERTY(EditAnywhere, Category = "Potions")
	float potionsHealPower;
};
