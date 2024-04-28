// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

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
}

void UHealthComponent::Heal(float healAmount)
{
	CheckIsDead();
	if (!isDead)
		currentHealth = std::min(currentHealth + healAmount, maxHealth);
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

