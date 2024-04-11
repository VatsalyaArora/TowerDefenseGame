// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResourceSystem.generated.h"

USTRUCT(BlueprintType)
struct FTowerResource : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString TowerName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ResourceNeeded;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 TimesSpawned;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxTimesSpawn;	
};





UCLASS()
class TOWERDEFENSE_API AResourceSystem : public AActor
{
	GENERATED_BODY()
		
public:	
	// Sets default values for this actor's properties
	AResourceSystem();

	UPROPERTY(EditAnywhere, Category = "Resource")
	int32 MaxCoins;

	UPROPERTY(EditAnywhere, Category = "Resource")
	int32 Coins;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Resource")
	class UDataTable* DataTableResourceRequired;

	UFUNCTION(BlueprintCallable, Category = "Resource")
	void SetMaxCoins(int32 mCoins);

	UFUNCTION(BlueprintCallable, Category = "Resource")
	void SetCoins(int32 _coins);

	UFUNCTION(BlueprintCallable, Category = "Resource")
	void AddCoins(int32 _coins);

	UFUNCTION(BlueprintCallable, Category = "Resource")
	void ReduceCoins(int32 _coins);

	UFUNCTION(BlueprintCallable, Category = "Resource")
	void UpdateTowerTimes(FString TowerName, bool SpawnedOrDestroyed);

	UFUNCTION(BlueprintPure, Category = "Resource")
	int32 GetMaxCoins();

	UFUNCTION(BlueprintPure, Category = "Resource")
	int32 GetCoins();

	UFUNCTION(BlueprintCallable, Category = "Resource")
	int32 ReturnRequiredResources(FString TowerName);

	UFUNCTION(BlueprintCallable, Category = "Resource")
	int32 FindMaxTowerCanSpawn(FString TowerName);

	UFUNCTION(BlueprintCallable, Category = "Resource")
	int32 FindTowerSpawned(FString TowerName);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
