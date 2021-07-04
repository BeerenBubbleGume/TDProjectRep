// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/TDPreviewBuilding_CPP.h"
#include "FunctionalAITest.h"
#include "Controllers/MainPlayerController_CPP.h"
#include "Kismet/GameplayStatics.h"
#include "Tasks/GameplayTask_SpawnActor.h"

// Sets default values
ATDPreviewBuilding_CPP::ATDPreviewBuilding_CPP()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATDPreviewBuilding_CPP::SpawnPreview(TSubclassOf<class ATDBuildingMaster_CPP> _BuildClass, UStaticMesh* DisplayMesh_)
{
	if (bIsPreviewing == false)
	{
		_BuildingClass = _BuildClass;
		_DisplayMesh = DisplayMesh_;
		bIsPreviewing = true;
		BuildingPreviewMesh->SetStaticMesh(_DisplayMesh);
	}
	else
	{
		DestroyPreview();
		_DisplayMesh = DisplayMesh_;
		bIsPreviewing = true;
		BuildingPreviewMesh->SetStaticMesh(_DisplayMesh);
	}
}

void ATDPreviewBuilding_CPP::ConstructBuilding(TSubclassOf<class ATDBuildingMaster_CPP> BuildingMasterClass)
{
	FTransform EmptyTransform = FTransform();
	AMainPlayerController_CPP* PlayerControllerRef = Cast<AMainPlayerController_CPP>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	PlayerControllerRef->GetWorld()->SpawnActorAbsolute(BuildingMasterClass, EmptyTransform, SpawnInfo);

	/*
	*finding a UStaticMesh component in other Files
	*/
	
	auto FoundComponents = GetComponentByClass(ATDBuildingMaster_CPP::StaticClass());
	if(FoundComponents != nullptr){
		UStaticMesh* DisplayMesh = Cast<UStaticMesh>(FoundComponents);
		if (DisplayMesh)
		{
			ATDBuildingMaster_CPP* CastingClass = Cast<ATDBuildingMaster_CPP>(BuildingMasterClass);
			DestroyPreview();
			SpawnPreview(BuildingMasterClass, DisplayMesh);
		}
	}
	/*
	UStaticMesh* NewComponent = NewObject<UStaticMesh>(ATDBuildingMaster_CPP::StaticClass(), "DisplayMesh");
	DestroyPreview();
	SpawnPreview(BuildingMasterClass, NewComponent);
	*/
}

void ATDPreviewBuilding_CPP::DestroyPreview()
{
	_BuildingClass = nullptr;
	_DisplayMesh = nullptr;
	bIsPreviewing = false;
	BuildingPreviewMesh->SetStaticMesh(_DisplayMesh);
}