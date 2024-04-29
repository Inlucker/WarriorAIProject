// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHPWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/HealthComponent.h"

void UPlayerHPWidget::NativeConstruct()
{
	UUserWidget::NativeConstruct();

	Player = Cast<AWarriorAIProjectCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

float UPlayerHPWidget::CalculateHealthPercentage()
{
	if (Player)
	{
		UHealthComponent* healthComponent = Player->FindComponentByClass<UHealthComponent>();
		if (healthComponent)
			return healthComponent->GetHealth() / healthComponent->GetMaxHealth();
	}
	return 0.f;
}