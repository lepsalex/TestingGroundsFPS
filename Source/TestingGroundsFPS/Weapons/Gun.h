// © Alexandru Lepsa 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class TESTINGGROUNDSFPS_API AGun : public AActor {
    GENERATED_BODY()

    /** Gun mesh: 1st person view (seen only by self) */
    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    class USkeletalMeshComponent * FP_Gun;

    /** Location on gun mesh where projectiles should spawn. */
    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    class USceneComponent * FP_MuzzleLocation;

  public:
    // Sets default values for this actor's properties
    AGun();

    /** Projectile class to spawn */
    UPROPERTY(EditDefaultsOnly, Category = Projectile)
    TSubclassOf<class ABallProjectile> ProjectileClass;

    /** Sound to play each time we fire */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
    class USoundBase * FireSound;

    /** AnimMontage to play each time we fire */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
    class UAnimMontage * FireAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
    class UAnimInstance * AnimInstance;

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    /** Fires a projectile. */
    UFUNCTION(BlueprintCallable, Category = "Shooting")
    void OnFire();

};
