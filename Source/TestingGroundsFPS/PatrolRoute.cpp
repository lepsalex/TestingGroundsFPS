// © Alexandru Lepsa 2018

#include "PatrolRoute.h"

// Sets default values for this component's properties
UPatrolRoute::UPatrolRoute() {
    PrimaryComponentTick.bCanEverTick = false;
}

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const {
    return PatrolPoints;
}
