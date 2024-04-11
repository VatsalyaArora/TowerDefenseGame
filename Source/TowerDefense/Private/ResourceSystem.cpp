// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceSystem.h"

// Sets default values
AResourceSystem::AResourceSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AResourceSystem::SetMaxCoins(int32 mCoins)
{
	Coins = mCoins;
}

void AResourceSystem::SetCoins(int32 _coins)
{
	Coins = _coins;
}

void AResourceSystem::AddCoins(int32 _coins)
{
	Coins += _coins;
}

void AResourceSystem::ReduceCoins(int32 _coins)
{
	Coins -= _coins;
}

int32 AResourceSystem::GetMaxCoins()
{
	return MaxCoins;
}

int32 AResourceSystem::GetCoins()
{
	return Coins;
}

int32 AResourceSystem::ReturnRequiredResources(FString TowerName)
{	
	FTowerResource* rowData = DataTableResourceRequired->FindRow<FTowerResource>(FName(TowerName), "");
	return rowData->ResourceNeeded;
}

int32 AResourceSystem::FindMaxTowerCanSpawn(FString TowerName)
{
	FTowerResource* rowData = DataTableResourceRequired->FindRow<FTowerResource>(FName(TowerName), "");
	return rowData->MaxTimesSpawn;
}

int32 AResourceSystem::FindTowerSpawned(FString TowerName)
{
	FTowerResource* rowData = DataTableResourceRequired->FindRow<FTowerResource>(FName(TowerName), "");
	return rowData->TimesSpawned;
}

// Called when the game starts or when spawned
void AResourceSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResourceSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

