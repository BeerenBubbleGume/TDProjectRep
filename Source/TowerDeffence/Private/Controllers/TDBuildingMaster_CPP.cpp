// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/TDBuildingMaster_CPP.h"
#include "Components/BillboardComponent.h"

// Sets default values
ATDBuildingMaster_CPP::ATDBuildingMaster_CPP()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Buildboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingMesh"));

	RootComponent = Buildboard;
	BuildingMesh->SetupAttachment(Buildboard);
}

void ATDBuildingMaster_CPP::ConstructionScript(UStaticMesh* _DisplayMesh) const
{
	BuildingMesh->SetStaticMesh(_DisplayMesh);
}