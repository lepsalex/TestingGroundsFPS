// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ThirdPersonCharacter_BP.h"
#include "Containers/Array.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

    // Get patrol points
    auto AIController = OwnerComp.GetAIOwner();
    auto PatollingGaurd = Cast<AThirdPersonCharacter_BP>(AIController->GetPawn());

    auto PatrolPoints = PatollingGaurd->GetPatrolPoints();

    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    auto IndexValue = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

    BlackboardComp->SetValueAsObject(NextWaypointKey.SelectedKeyName, PatrolPoints[IndexValue]);

    int32 NextIndexValue = (IndexValue + 1) % PatrolPoints.Num();
    BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndexValue);

    return EBTNodeResult::Succeeded;
}
