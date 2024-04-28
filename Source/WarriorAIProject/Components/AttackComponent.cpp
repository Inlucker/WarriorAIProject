// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"
#include "HealthComponent.h"

// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAttackComponent::CallAttack()
{
	AActor* owner = GetOwner();
	if (owner)
	{
		UHealthComponent* healthComponent = owner->FindComponentByClass<UHealthComponent>();
		if (healthComponent)
		{
			if (!healthComponent->IsDead())
				OnAttack.Broadcast();
		}
		else
			OnAttack.Broadcast();
	}
}

void UAttackComponent::CallAttackFinished()
{
	OnAttackFinished.Broadcast();
}