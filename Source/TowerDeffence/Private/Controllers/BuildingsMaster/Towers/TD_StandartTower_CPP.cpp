// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/BuildingsMaster/Towers/TD_StandartTower_CPP.h"

ATD_StandartTower_CPP::ATD_StandartTower_CPP()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StandartTowersAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/Turret3.Turret3'"));
	if (StandartTowersAsset.Succeeded())
	{
		ConstructionScript(StandartTowersAsset.Object);
	}
}