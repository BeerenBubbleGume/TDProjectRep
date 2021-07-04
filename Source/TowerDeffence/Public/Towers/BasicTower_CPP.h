// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagsSettings.h"
#include "GameFramework/Pawn.h"
#include "TowerDeffence/CPP_TowersProjectile.h"

#include "BasicTower_CPP.generated.h"

UCLASS()
class TOWERDEFFENCE_API ABasicTower_CPP : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasicTower_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FName Enemy;
	FTimerHandle loopTimer;
	FTimerDelegate TimerDel;
	
	//Turn Tower Head to Enemy
	void RotationTowerHead(AActor* FindetEnemy);

	//Calculate length to Enemy
	float GetLengthToTurret(AActor* Reference);

	//Find Enemy by Tag
	void FindEnemy();

	//Make turret to fire by Enemy
	//void FireToEnemy();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
	TSubclassOf<ACPP_TowersProjectile> BP_TowersProjectile;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Class To Find")
	TSubclassOf<ACharacter> ClassToFind;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* TowersBase;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* TowersHead;
	
	UPROPERTY(BlueprintReadWrite, Category = "Scene")
	USceneComponent* Root;
	
	UPROPERTY(BlueprintReadWrite, Category = "Vareables")
	bool CanSpawnTower;
	
};
