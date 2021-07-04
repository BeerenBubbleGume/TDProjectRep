// Fill out your copyright notice in the Description page of Project Settings.


#include "Volum/SpawnerAI.h"

#include "Characters/EnemysCharacter_CPP.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpawnerAI::ASpawnerAI()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if(CubeAsset.Succeeded())
	{
		Mesh->SetStaticMesh(CubeAsset.Object);
		Mesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		Mesh->SetWorldScale3D(FVector(1, 1, 0.02f));
	}
	
}

// Called when the game starts or when spawned
void ASpawnerAI::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(loopTimer, this, &ASpawnerAI::SpawnAI, 2.f, true, -0.25f);
	
}

// Called every frame
void ASpawnerAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnerAI::SpawnAI() const
{
	const FVector SpawnerLocation = Mesh->GetComponentLocation();
	const FVector InScale3D = FVector(1.f);
	const FRotator SpawnerRotation = GetActorRotation();
	const FTransform SpawnLocation = FTransform(SpawnerRotation, SpawnerLocation, InScale3D);
	UWorld* World = GetWorld();
	if( World )
	{
		AEnemysCharacter_CPP* NewActor = World->SpawnActorDeferred<AEnemysCharacter_CPP>(AEnemysCharacter_CPP::StaticClass(), FTransform::Identity, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);
		UGameplayStatics::FinishSpawningActor(NewActor, SpawnLocation);
	}
	
}

