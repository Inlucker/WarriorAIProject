// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AWarriorCharacter::AWarriorCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	AttackComponent = CreateDefaultSubobject<UAttackComponent>(TEXT("AttackComponent"));
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));
}

// Called when the game starts or when spawned
void AWarriorCharacter::BeginPlay()
{
	Super::BeginPlay();

	startPos = GetActorLocation();	
}

// Called every frame
void AWarriorCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWarriorCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector AWarriorCharacter::GetPatrolMidLocation() const
{
	return startPos;
}

float AWarriorCharacter::SetMoveSpeed(EMoveSpeed speed)
{
	float newSpeed = -1;

	UCharacterMovementComponent* charMoveComp = FindComponentByClass<UCharacterMovementComponent>();
	if (charMoveComp)
	{
		switch (speed)
		{
		case EMoveSpeed::Idle:
			newSpeed = 0;
			break;
		case EMoveSpeed::Walking:
			newSpeed = 100;
			break;
		case EMoveSpeed::Jogging:
			newSpeed = 300;
			break;
		case EMoveSpeed::Sprinting:
			newSpeed = 500;
			break;
		}

		charMoveComp->MaxWalkSpeed = newSpeed;
	}

	return newSpeed;
}

