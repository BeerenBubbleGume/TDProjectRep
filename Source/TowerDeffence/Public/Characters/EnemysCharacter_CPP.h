// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "EnemysCharacter_CPP.generated.h"

UCLASS()
class TOWERDEFFENCE_API AEnemysCharacter_CPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemysCharacter_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float Health = 250.f;
	bool Dead;
	

	void HitDestoy(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	TArray<AActor*> Waypoint;

	int CurrentWaypoint = 0;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AActor* CharacterTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTags")
	FGameplayTagContainer Actor;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void GoToWaypoint();

	UPROPERTY(BlueprintReadWrite, Category = "Collision Capsule")
	UCapsuleComponent* CollisionCapsule;

	UPROPERTY(BlueprintReadWrite, Category = "MeshComponent")
	USkeleton* meshSkeleton;
	UPROPERTY(BlueprintReadWrite, Category = "MeshComponent")
	UMeshComponent* SMesh;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const { TagContainer = Actor; return; }

	UPROPERTY(EditAnywhere,Category = "AI")
	class UBehaviorTree* BehaviorTree;

	
};
