// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "Characters/EnemysCharacter_CPP.h"
#include "Kismet/GameplayStatics.h"
#include "Navigation/TargetDefencesPoint_CPP.h"

AEnemyAIController::AEnemyAIController()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	TargetLocationKey = "TargetLocation";
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
}

void AEnemyAIController::MoveToTargetPoint()
{
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::Possess(InPawn);

	//Get the possessed Character and check if it's my own AI Character
	AEnemysCharacter_CPP* AIChar = Cast<AEnemysCharacter_CPP>(InPawn);
	EAutoPossessAI::Spawned;
	FString Path = "/Game/TopDownCPP/Blueprints/AI/EnemyBT_BP.EnemyBT_BP";
	UBehaviorTree* Tree = Cast<UBehaviorTree>(StaticLoadObject(UBehaviorTree::StaticClass(), nullptr, *Path));

	if (AIChar)
	{
		//If the blackboard is valid initialize the blackboard for the corresponding behavior tree
		if (AIChar->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AIChar->BehaviorTree->BlackboardAsset));
		}
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetDefencesPoint_CPP::StaticClass(), BotTargetPoints);

		BehaviorComp->StartTree(*AIChar->BehaviorTree);
	}
}