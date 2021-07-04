// Fill out your copyright notice in the Description page of Project Settings.


#include "Towers/BasicTower_CPP.h"

#include "GeneratedCodeHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABasicTower_CPP::ABasicTower_CPP()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TowersBase = CreateDefaultSubobject<UStaticMeshComponent>("TowerBase");
	TowersHead = CreateDefaultSubobject<UStaticMeshComponent>("TowersHead");
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	
	RootComponent = Root;
	TowersBase->SetupAttachment(Root);
	TowersHead->SetupAttachment(Root);

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TowersBaseAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/Turret_Base_OBJ.Turret_Base_OBJ'"));
	if(TowersBaseAsset.Succeeded())
	{
		TowersBase->SetStaticMesh(TowersBaseAsset.Object);
		TowersBase->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		TowersBase->SetRelativeRotation(FRotator(0.f, 0.f, 90.f));
		TowersBase->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	}
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TowersHeadAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/Turret_Head_OBJ.Turret_Head_OBJ'"));
	if(TowersHeadAsset.Succeeded())
	{
		TowersHead->SetStaticMesh(TowersHeadAsset.Object);
		TowersHead->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		TowersHead->SetRelativeRotation(FRotator(0.f, 270.f, 90.f));
		TowersHead->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	}
	
}

// Called when the game starts or when spawned
void ABasicTower_CPP::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(loopTimer, TimerDel, 1.5f, true, -1.f);
}

void ABasicTower_CPP::RotationTowerHead(AActor* FindetEnemy)
{
	//ACPP_MobsCharacters* AMyClass = Cast<ACPP_MobsCharacters>(FindetEnemy);
	FVector PlayerLocation = FindetEnemy->GetActorLocation();
	FVector TowersHeadLocation = TowersHead->GetComponentLocation();
	float Lenth = GetDistanceTo(FindetEnemy);
	if(FindetEnemy != nullptr)
	{
		if(Lenth <= 800.f)
		{
			/*Set Rotation degree*/
			FRotator HeadRot = UKismetMathLibrary::FindLookAtRotation(TowersHeadLocation, PlayerLocation);
			FRotator MyRotator = UKismetMathLibrary::MakeRotator(0, 0, HeadRot.Yaw);
			TowersHead->SetRelativeRotation(MyRotator, false, nullptr, ETeleportType::None);
			
			FRotator HeadSeeDegree = TowersHead->GetComponentRotation();
			FVector InScale3D = FVector(1.f);
			FTransform Location = FTransform(HeadSeeDegree, TowersHeadLocation, InScale3D);
		
			UWorld* World = GetWorld();
			if( World )
			{
				ACPP_TowersProjectile* SpawnPeojectile = World->SpawnActorDeferred<ACPP_TowersProjectile>(ACPP_TowersProjectile::StaticClass(), FTransform::Identity, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
				UGameplayStatics::FinishSpawningActor(SpawnPeojectile, Location);
				TimerDel.BindUFunction(this, FName("RotationTowerHead"), FindetEnemy);
			}
		}
	}
	
}

float ABasicTower_CPP::GetLengthToTurret(AActor* Reference)
{
	AActor* FindetEnemy = Reference;
	FVector EnemyLocation = FindetEnemy->GetActorLocation();
	FVector TowerLocation =  TowersHead->GetComponentLocation();
	float LenthToEnemy = TowerLocation.Size() - EnemyLocation.Size();
	
	return LenthToEnemy;
}

void ABasicTower_CPP::FindEnemy()
{
	TArray<AActor*> FindEnemyWithTags;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), Enemy, FindEnemyWithTags);
	int32 EnemyArrayLength = FCustomThunkTemplates::Array_Length(FindEnemyWithTags);
	if(EnemyArrayLength != 0)
	{
		int CurrentIndex = 0;
		for(int Index = 0; Index <= EnemyArrayLength; ++Index)
		{
			if(Index != NULL)
			{
				AActor* CurrentEnemy = FindEnemyWithTags[Index];
				float Lenth = GetLengthToTurret(CurrentEnemy);
				float MinLength = 900.f;
				if(Lenth <= MinLength)
				{
					MinLength = Lenth;
					CurrentIndex = Index;
					RotationTowerHead(FindEnemyWithTags[CurrentIndex]);	
				}
			}
		}
	}
		
}

// Called every frame
void ABasicTower_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FindEnemy();
}

