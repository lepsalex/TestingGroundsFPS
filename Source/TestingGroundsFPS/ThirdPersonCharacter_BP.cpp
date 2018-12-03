// Fill out your copyright notice in the Description page of Project Settings.

#include "ThirdPersonCharacter_BP.h"

TArray<AActor*> AThirdPersonCharacter_BP::GetPatrolPoints() const {
    return PatrolPoints;
}