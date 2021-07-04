// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerAI.generated.h"

UCLASS()
class TOWERDEFFENCE_API ASpawnerAI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle loopTimer;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Mesh)
	UStaticMeshComponent* Mesh;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnAI() const;
};
