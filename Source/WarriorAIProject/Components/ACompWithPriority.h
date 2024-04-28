// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ACompWithPriority.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIORAIPROJECT_API UACompWithPriority : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Priority")
	virtual int GetPriority() const;

	UFUNCTION(BlueprintCallable, Category = "Priority")
	virtual void SetPriority(int newPriority);

protected:
	UPROPERTY(EditAnywhere, Category = "Priority")
	int priority;
};
