// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile_Base.generated.h"

UCLASS()
class TOWERDEFENSE_API ATile_Base : public AActor, public UNavAreaBase
{
	GENERATED_BODY()

public:
	//Varibales

	UPROPERTY(EditAnywhere, Category = "Tile")
	int gridPosX;

	UPROPERTY(EditAnywhere, Category = "Tile")
	int gridPosY;

	UPROPERTY(EditAnywhere, Category = "Tile")
	bool isOccupied;

	UPROPERTY(EditAnywhere, Category = "Tile")
	float TimeToOccupyAgain;

	UPROPERTY(EditAnywhere, Category = "Tile")
	bool CanPlayerSpawn;

	UPROPERTY(EditAnywhere, Category = "Tile")
	float StayTimer;
	
	
public:	
	// Sets default values for this actor's properties
	ATile_Base();

	UFUNCTION(BlueprintCallable, Category = "Tile")
	void SetTileSpawnable(bool _canPlayerSpawn);

	UFUNCTION(BlueprintCallable, Category = "Tile")
	void SetTimer(float time);

	UFUNCTION(BlueprintCallable, Category = "Tile")
	void SetGridPos(int x, int y);

	UFUNCTION(BlueprintCallable, Category = "Tile")
	void SetOccupied(bool occupied);

	UFUNCTION(BlueprintCallable, Category = "Tile")
	void SetStayTimer(float _timer);

	UFUNCTION(BlueprintPure, Category = "Tile")
	bool GetTileSpawnable();

	UFUNCTION(BlueprintPure, Category = "Tile")
	float GetTimer();

	UFUNCTION(BlueprintPure, Category = "Tile")
	int GetGridPosX();

	UFUNCTION(BlueprintPure, Category = "Tile")
	int GetGridPosY();

	UFUNCTION(BlueprintPure, Category = "Tile")
	bool GetOccupied();

	UFUNCTION(BlueprintPure, Category = "Tile")
	float GetStayTimer();


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
