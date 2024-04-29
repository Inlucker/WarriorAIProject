// Fill out your copyright notice in the Description page of Project Settings.


#include "AICEnemyBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Damage.h"
#include "Components/HealthComponent.h"
#include "GameFramework/Character.h"

AAICEnemyBase::AAICEnemyBase()
{
  AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
  UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
  SightConfig->SightRadius = 1000.0f;
  SightConfig->LoseSightRadius = SightConfig->SightRadius + 500.0f;
  SightConfig->PeripheralVisionAngleDegrees = 50.0f;
  SightConfig->SetMaxAge(5.0f);
  SightConfig->DetectionByAffiliation.bDetectEnemies = true;
  SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
  SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
  SightConfig->PointOfViewBackwardOffset = 150;
  SightConfig->NearClippingRadius = 150;
  AIPerceptionComponent->ConfigureSense(*SightConfig);

  UAISenseConfig_Hearing* HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
  HearingConfig->HearingRange = 1500.0f;
  HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
  HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
  HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
  AIPerceptionComponent->ConfigureSense(*HearingConfig);

  UAISenseConfig_Damage* DamageConfig = CreateDefaultSubobject<UAISenseConfig_Damage>(TEXT("DamageConfig"));
  DamageConfig->SetMaxAge(5.0f);
  AIPerceptionComponent->ConfigureSense(*DamageConfig);

  AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AAICEnemyBase::HandleSense);
}

void AAICEnemyBase::SetStateAsPassive()
{
  UBlackboardComponent* blackBoard = GetBlackboardComponent();
  if (!blackBoard) return;
  blackBoard->SetValueAsEnum(FName(TEXT("State")), static_cast<uint8>(EStateEnemyBase::Passive));
}

void AAICEnemyBase::SetStateAsDead()
{
  UBlackboardComponent* blackBoard = GetBlackboardComponent();
  if (!blackBoard) return;
  blackBoard->SetValueAsEnum(FName(TEXT("State")), static_cast<uint8>(EStateEnemyBase::Dead));
}

void AAICEnemyBase::SetStateAsAttacking(AActor* AttackTarget)
{
  UBlackboardComponent* blackBoard = GetBlackboardComponent();
  if (!blackBoard) return;
  blackBoard->SetValueAsObject(FName(TEXT("AttackTarget")), AttackTarget);
  blackBoard->SetValueAsVector(FName(TEXT("LastKnownLocation")), AttackTarget->GetActorLocation());
  blackBoard->SetValueAsEnum(FName(TEXT("State")), static_cast<uint8>(EStateEnemyBase::Attacking));
}

void AAICEnemyBase::SetStateAsInvestigating(FVector location)
{
  UBlackboardComponent* blackBoard = GetBlackboardComponent();
  if (!blackBoard) return;
  blackBoard->SetValueAsVector(FName(TEXT("PointOfInterest")), location);
  blackBoard->SetValueAsEnum(FName(TEXT("State")), static_cast<uint8>(EStateEnemyBase::Investigating));
}

EStateEnemyBase AAICEnemyBase::GetCurrentState()
{
  UBlackboardComponent* blackBoard = GetBlackboardComponent();
  if (!blackBoard) return (EStateEnemyBase::Unknown);
  return static_cast<EStateEnemyBase>(blackBoard->GetValueAsEnum(TEXT("State")));
}


void AAICEnemyBase::HandleSense(AActor* Actor, FAIStimulus Stimulus)
{
  EStateEnemyBase state = GetCurrentState();
  if (state == EStateEnemyBase::Dead) return;

  UHealthComponent* healthComponent = Actor->FindComponentByClass<UHealthComponent>();
  if (healthComponent && healthComponent->IsDead())
    return;

  const APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
  if (PlayerController)
  {
    const ACharacter* PlayerCharacter = PlayerController->GetCharacter();
    const ACharacter* ActorCharacter = Cast<ACharacter>(Actor);

    if (!PlayerCharacter || !ActorCharacter || ActorCharacter != PlayerCharacter)
      return;
  }
  else
    return;

  if (Stimulus.Type == UAISense_Damage::GetSenseID<UAISense_Damage>())
  {
    if (Stimulus.WasSuccessfullySensed() && state != EStateEnemyBase::Attacking)
      SetStateAsAttacking(Actor);
  }
  else if (Stimulus.Type == UAISense_Hearing::GetSenseID<UAISense_Hearing>())
  {
    if (Stimulus.WasSuccessfullySensed() && state != EStateEnemyBase::Attacking)
      SetStateAsInvestigating(Stimulus.StimulusLocation);
  }
  else if (Stimulus.Type == UAISense_Sight::GetSenseID<UAISense_Sight>())
  {
    if (Stimulus.WasSuccessfullySensed())
      SetStateAsAttacking(Actor);
    else
    {
      UBlackboardComponent* blackBoard = GetBlackboardComponent();
      if (!blackBoard) return;
      blackBoard->SetValueAsObject(FName(TEXT("AttackTarget")), nullptr);
      blackBoard->SetValueAsVector(FName(TEXT("LastKnownLocation")), Stimulus.StimulusLocation);
    }
  }
}