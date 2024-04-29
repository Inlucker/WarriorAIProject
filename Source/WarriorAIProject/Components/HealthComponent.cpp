// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "HealPotionsComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent() : isDead(false)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CheckIsDead();
}


void UHealthComponent::CheckIsDead()
{
	if (currentHealth <= 0.0f && !isDead)
	{
		isDead = true;
		OnDeath.Broadcast();  // ֲûחמג סמבûעטÿ סלונעט
	}
}

float UHealthComponent::GetHealth() const
{
	return currentHealth;
}

float UHealthComponent::GetMaxHealth() const
{
	return maxHealth;
}

void UHealthComponent::TakeDamage(float damageAmount)
{
	currentHealth -= std::min(damageAmount, currentHealth);
	CheckIsDead();
	if (!isDead &&(currentHealth / maxHealth) <= 0.3)
	{
		AActor* owner = GetOwner();
		if (owner)
		{
			UHealPotionsComponent* healPotionsComponent = owner->FindComponentByClass<UHealPotionsComponent>();
			if (healPotionsComponent)
				healPotionsComponent->SetPriority(100);
		}
	}
}

void UHealthComponent::Heal(float healAmount)
{
	CheckIsDead();
	if (!isDead)
	{
		currentHealth = std::min(currentHealth + healAmount, maxHealth);

		if ((currentHealth / maxHealth) > 0.3)
		{
			AActor* owner = GetOwner();
			if (owner)
			{
				UHealPotionsComponent* healPotionsComponent = owner->FindComponentByClass<UHealPotionsComponent>();
				if (healPotionsComponent)
					healPotionsComponent->SetPriority(0);
			}
		}
	}
}

bool UHealthComponent::IsDead() const
{
	return isDead;
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

