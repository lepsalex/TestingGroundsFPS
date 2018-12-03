// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

    // Get patrol route component
    auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
    auto PatrolRouteComp = ControlledPawn->FindComponentByClass<UPatrolRoute>();
    if (!ensure(PatrolRouteComp)) { return EBTNodeResult::Failed; }

    // Get patrol points
    auto PatrolPoints = PatrolRouteComp->GetPatrolPoints();
    if (PatrolPoints.Num() == 0) {
        UE_LOG(LogTemp, Warning, TEXT("%s is missing patrol points"), *ControlledPawn->GetName());
    }

    // Set next WP
    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    auto IndexValue = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    BlackboardComp->SetValueAsObject(NextWaypointKey.SelectedKeyName, PatrolPoints[IndexValue]);

    // Cycle to next WP
    int32 NextIndexValue = (IndexValue + 1) % PatrolPoints.Num();
    BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndexValue);

    return EBTNodeResult::Succeeded;
}
