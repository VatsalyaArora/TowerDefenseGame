// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "EnemyQueue.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWERDEFENSE_API UEnemyQueue : public UActorComponent
{
	GENERATED_BODY()

	TMap<int,APawn*> enemies;
	int totalEnemyCount = 0;
	int currentEnemyCount = 0;
public:	
	// Sets default values for this component's properties
	UEnemyQueue();

	UFUNCTION(BlueprintCallable, Category = "Enemies")
	void AddEnemy(APawn* enemy);

	UFUNCTION(BlueprintCallable, Category = "Enemies")
	APawn* GetLastEnemy();

	UFUNCTION(BlueprintCallable, Category = "Enemies")
	bool RemoveEnemy(APawn* enemy);

	UFUNCTION(BlueprintCallable, Category = "Enemies")
	int GetQueueSize();

		
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
