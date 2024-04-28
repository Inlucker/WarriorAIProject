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
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintPure)
	float CalculateHealthPercentage();

	UPROPERTY(VisibleAnywhere)
	AWarriorAIProjectCharacter* Player;
};
