// Fill out your copyright notice in the Description page of Project Settings.


#include "Navigation/Waypoints_DefenseBase.h"

// Sets default values
AWaypoints_DefenseBase::AWaypoints_DefenseBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AWaypoints_DefenseBase::GetWaypointOrder()
{
	return Waypoint;
}

// Called when the game starts or when spawned
void AWaypoints_DefenseBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaypoints_DefenseBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

