// © Alexandru Lepsa 2018

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "ThirdPersonCharacter_BP.generated.h"

/**
 *
 */
UCLASS()
class TESTINGGROUNDSFPS_API AThirdPersonCharacter_BP : public ATP_ThirdPersonCharacter {
    GENERATED_BODY()

  public:
    TArray<AActor*> GetPatrolPoints() const;

  private:
    UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
    TArray<AActor*> PatrolPoints;
};
