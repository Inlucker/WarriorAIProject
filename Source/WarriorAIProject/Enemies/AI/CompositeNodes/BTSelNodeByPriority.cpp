// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSelNodeByPriority.h"
#include "HasPriority.h"

int32 UBTSelNodeByPriority::GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const
{
  int32 NextChildIdx = PrevChild + 1;
  if (PrevChild == BTSpecialChild::NotInitialized)
  {
    int BestChildIdx = BTSpecialChild::NotInitialized;
    int HighestPriority = INT_MIN;

    for (int32 ChildIdx = 0; ChildIdx < GetChildrenNum(); ChildIdx++)
    {
      const UBTNode* Node = GetChildNode(ChildIdx);
      int priority = -1;
      const IHasPriority* NodeWithPriotiry = Cast<IHasPriority>(Node);
      if (NodeWithPriotiry)
      {
        AAIController* AIController = SearchData.OwnerComp.GetAIOwner();
        priority = NodeWithPriotiry->GetPriority(AIController);
      }

      if (priority > HighestPriority)
      {
        HighestPriority = priority;
        BestChildIdx = ChildIdx;
      }
    }

    return BestChildIdx;
  }
  else if (LastResult == EBTNodeResult::Failed)
  {
    int BestChildIdx = BTSpecialChild::NotInitialized;
    int HighestPriority = INT_MIN;

    for (int32 ChildIdx = 0; ChildIdx < GetChildrenNum(); ChildIdx++)
    {
      if (ChildIdx == PrevChild)
        continue;
      const UBTNode* Node = GetChildNode(ChildIdx);
      int priority = -1;
      const IHasPriority* NodeWithPriotiry = Cast<IHasPriority>(Node);
      if (NodeWithPriotiry)
      {
        AAIController* AIController = SearchData.OwnerComp.GetAIOwner();
        priority = NodeWithPriotiry->GetPriority(AIController);
      }

      if (priority > HighestPriority)
      {
        HighestPriority = priority;
        BestChildIdx = ChildIdx;
      }
    }

    return BestChildIdx;
  }

  return BTSpecialChild::ReturnToParent;
}