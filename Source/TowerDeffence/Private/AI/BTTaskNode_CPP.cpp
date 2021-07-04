// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/BTTaskNode_CPP.h"
#include "AI/EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/TargetDefencesPoint_CPP.h"

EBTNodeResult::Type UBTTaskNode_CPP::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAIController* AICon = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		ATargetDefencesPoint_CPP* CurrentPoint = Cast<ATargetDefencesPoint_CPP>(BlackboardComp->GetValueAsObject("TargetLocation"));

		TArray<AActor*> AvailableTargetPoints = AICon->GetAvailableTargetPoints();

		int32 RandomIndex;

		ATargetDefencesPoint_CPP* NextTargetPoint = nullptr;

		do
		{
			RandomIndex = FMath::RandRange(0, AvailableTargetPoints.Num() - 1);

			//Remember that the Array provided by the Controller function contains AActor* objects so we need to cast.
			NextTargetPoint = Cast<ATargetDefencesPoint_CPP>(AvailableTargetPoints[RandomIndex]);
		} while (CurrentPoint == NextTargetPoint);

		BlackboardComp->SetValueAsObject("TargetLocation", NextTargetPoint);

		//At this point, the task has been successfully completed
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}