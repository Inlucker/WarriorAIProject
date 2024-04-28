// Fill out your copyright notice in the Description page of Project Settings.


#include "HealPotionsComponent.h"
#include "HealthComponent.h"

// Sets default values for this component's properties
UHealPotionsComponent::UHealPotionsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealPotionsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealPotionsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UHealPotionsComponent::GetPotionsAmount()
{
	return potionsAmount;
}

int UHealPotionsComponent::AddPotions(int addPotionsAmount)
{
	potionsAmount += addPotionsAmount;
	return potionsAmount;
}

int UHealPotionsComponent::UsePotion()
{
	if (potionsAmount <= 0)
		return potionsAmount;
	AActor* owner = GetOwner();
	if (owner)
	{
		UHealthComponent* healthComponent = owner->FindComponentByClass<UHealthComponent>();
		if (healthComponent)
		{
			healthComponent->Heal(potionsHealPower);
			--potionsAmount;
		}
	}
	return potionsAmount;
}

void UHealPotionsComponent::CallUsePotionStart()
{
	OnUsePotionStart.Broadcast();
}

void UHealPotionsComponent::CallUsePotionEnd()
{
	OnUsePotionEnd.Broadcast();
}

