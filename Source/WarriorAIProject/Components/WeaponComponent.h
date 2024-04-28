// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEquipDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEquipFinishedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnequipDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnequipFinishedDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIORAIPROJECT_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void CallEquip();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void CallEquipFinished();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void CallUnequip();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void CallUnequipFinished();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool IsEquiped();

public:
	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnEquipDelegate OnEquip;

	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnEquipFinishedDelegate OnEquipFinished;

	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnUnequipDelegate OnUnequip;

	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnUnequipFinishedDelegate OnUnequipFinished;

protected:
	bool _isEquiped;
};
