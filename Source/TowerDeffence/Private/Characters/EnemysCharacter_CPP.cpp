// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/EnemysCharacter_CPP.h"
#include "Actions/PawnActionsComponent.h"
#include "AI/EnemyAIController.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Navigation/TargetDefencesPoint_CPP.h"

// Sets default values
AEnemysCharacter_CPP::AEnemysCharacter_CPP()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	Actor.AddTag(FGameplayTag::RequestGameplayTag(FName("Character.Enemy")));

	AIControllerClass = AEnemyAIController::StaticClass();
	
	
	
	PrimaryActorTick.bCanEverTick = true;

	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>("CollisionCapsule");
	meshSkeleton = CreateDefaultSubobject<USkeleton>(TEXT("meshskeleton_1"));

	CollisionCapsule->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skMeshAsset(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin"));
	if (skMeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(skMeshAsset.Object);
		GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -97.f));
		GetMesh()->SetRelativeRotation(FRotator(0.f, 270.f, 0.f));
		GetMesh()->SetVisibility(true, true);
		GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
		GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	}

	static ConstructorHelpers::FObjectFinder<USkeleton> skeletonObj(TEXT("/Game/Mannequin/Character/Mesh/UE4_Mannequin_Skeleton.UE4_Mannequin_Skeleton"));
	if (skeletonObj.Succeeded())
	{
		meshSkeleton = skeletonObj.Object;
	}

}

// Called when the game starts or when spawned
void AEnemysCharacter_CPP::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetDefencesPoint_CPP::StaticClass(), Waypoint);
	
	GoToWaypoint();
}

void AEnemysCharacter_CPP::HitDestoy(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherComponent != NULL) && OtherComponent->IsSimulatingPhysics())
	{
		if (GEngine)
		{
			K2_DestroyActor();
			UE_LOG(LogTemp, Warning, TEXT("Destroy Actor"));
		}
	}
}

// Called every frame
void AEnemysCharacter_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemysCharacter_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void AEnemysCharacter_CPP::GoToWaypoint()
{
	
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());

	if (EnemyAIController)
	{
		if (CurrentWaypoint <= Waypoint.Num())
		{
			for (AActor* Waypoints : Waypoint)
			{
				ATargetDefencesPoint_CPP* WaypointItr = Cast<ATargetDefencesPoint_CPP>(Waypoints);
				if (WaypointItr)
				{
					if (WaypointItr->GetWaypointOrder() == CurrentWaypoint)
					{
						EnemyAIController->MoveToActor(WaypointItr, 5.f, false);
						CurrentWaypoint++;

						break;
					}
				}
			}
		}
	}
}
