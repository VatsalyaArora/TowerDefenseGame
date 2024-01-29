// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyQueue.h"

// Sets default values for this component's properties
UEnemyQueue::UEnemyQueue()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyQueue::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnemyQueue::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEnemyQueue::AddEnemy(APawn* enemy)
{
	enemies.Add(totalEnemyCount, enemy);
	totalEnemyCount++;
}

APawn* UEnemyQueue::GetLastEnemy()
{
	if (enemies.Num() > 0)
	{
		if (enemies.Contains(currentEnemyCount))
		{
			APawn* currentEnemy = enemies[currentEnemyCount];
			return currentEnemy;
		}
		else
		{
			currentEnemyCount++;
			GetLastEnemy();
		}
	}
	return nullptr;
}

bool UEnemyQueue::RemoveEnemy(APawn* _enemy)
{
	if (enemies.IsEmpty())
	{
		return false;
	}
	int key = -1;
	for (auto& pair : enemies)
	{
		if (pair.Value->GetName() == _enemy->GetName())
		{
			key = pair.Key;
			break;
		}
	}
	if (key != -1)
	{
		enemies.Remove(key);
		return true;
	}
	
	return false;
}
