// � Alexandru Lepsa 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class TESTINGGROUNDSFPS_API UPatrolRoute : public UActorComponent {
    GENERATED_BODY()

  public:
    // Sets default values for this component's properties
    UPatrolRoute();

    TArray<AActor*> GetPatrolPoints() const;

  private:
    UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
    TArray<AActor*> PatrolPoints;
};
