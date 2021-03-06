// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFFENCE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController();

	virtual void BeginPlay() override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	void MoveToTargetPoint();

	/*Behavior tree comp ref*/
	UBehaviorTreeComponent* BehaviorComp;
   
	/*----------Blackboard----------*/
 
	/*Blackboard comp ref*/
	UBlackboardComponent* BlackboardComp;
 
	/*Blackboard keys*/
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName TargetLocationKey;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName TargetActor;
	/*----------Blackboard----------*/
 
	/*I use the AActor class as the Template class so I can use the GetAllActorsOfClass function.
	However, in this collection I'm going to store all the Available ABotTargetPoint instances.*/
	TArray<AActor*> BotTargetPoints;
 
	/*Posses is executed when the character we want to control is spawned.
	Inside this function, we initialize the blackboard and start the behavior tree*/
	virtual void OnPossess(APawn* InPawn) override;

private:
    
	FTimerHandle TimerHandle;

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

public:
	
	FORCEINLINE TArray<AActor*> GetAvailableTargetPoints() const { return BotTargetPoints; }
	
};
