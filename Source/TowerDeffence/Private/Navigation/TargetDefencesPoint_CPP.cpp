// Fill out your copyright notice in the Description page of Project Settings.


#include "Navigation/TargetDefencesPoint_CPP.h"

#include "Kismet/GameplayStatics.h"

ATargetDefencesPoint_CPP::ATargetDefencesPoint_CPP()
{
	
}

int ATargetDefencesPoint_CPP::GetWaypointOrder() const
{
	return Waypoint;
}

void ATargetDefencesPoint_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void ATargetDefencesPoint_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
