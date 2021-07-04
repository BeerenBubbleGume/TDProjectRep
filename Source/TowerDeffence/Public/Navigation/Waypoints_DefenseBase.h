// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Waypoints_DefenseBase.generated.h"

UCLASS()
class TOWERDEFFENCE_API AWaypoints_DefenseBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaypoints_DefenseBase();

	int GetWaypointOrder();
	void BeginPlay();
	void Tick(float DeltaTime);

protected:
	UPROPERTY(EditAnywhere, meta = (AllowPrivatAccess = "true"))
	int Waypoint;
};
