// © Alexandru Lepsa 2018

#include "ThirdPersonCharacter_BP.h"

TArray<AActor*> AThirdPersonCharacter_BP::GetPatrolPoints() const {
    return PatrolPoints;
}