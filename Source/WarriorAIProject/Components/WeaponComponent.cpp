// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponComponent::CallEquip()
{
	_isEquipping = true;
	OnEquip.Broadcast();
}

void UWeaponComponent::CallEquipFinished()
{
	OnEquipFinished.Broadcast();
	_isEquipping = false;
}

void UWeaponComponent::CallUnequip()
{
	_isUnequipping = true;
	OnUnequip.Broadcast();
}

void UWeaponComponent::CallUnequipFinished()
{
	OnUnequipFinished.Broadcast();
	_isUnequipping = false;
}

bool UWeaponComponent::IsEquiped() const
{
	return _isEquiped;
}

void UWeaponComponent::SetIsEquiped(bool val)
{
	_isEquiped = val;
}

bool UWeaponComponent::IsEquipping() const
{
	return _isEquipping;
}

bool UWeaponComponent::IsUnequipping() const
{
	return _isUnequipping;
}

