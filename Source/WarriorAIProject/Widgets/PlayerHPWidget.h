// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../WarriorAIProjectCharacter.h"
#include "PlayerHPWidget.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORAIPROJECT_API UPlayerHPWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	// Begin Play alternative
	virtual void NativeConstruct() override;

	/** Function to calculate Player HP Percentage */
	UFUNCTION(BlueprintPure)
	float CalculateHealthPercentage();

	/** The player */
	UPROPERTY(VisibleAnywhere)
	AWarriorAIProjectCharacter* Player;
};
