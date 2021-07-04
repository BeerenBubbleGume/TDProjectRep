// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "TargetDefencesPoint_CPP.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFFENCE_API ATargetDefencesPoint_CPP : public ATargetPoint
{
	GENERATED_BODY()
public:
	ATargetDefencesPoint_CPP();
	
	int GetWaypointOrder() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, meta = (AllowPrivatAccess = "true"))
	int Waypoint;
};
