// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile_Base.h"
#include "Grid_Base.generated.h"


UCLASS()
class TOWERDEFENSE_API AGrid_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrid_Base();

	//Variables
	UPROPERTY(BlueprintReadWrite, Category = "Grid")
	int totalTiles;

	UPROPERTY(EditAnywhere, Category = "Grid")
	int Width;

	UPROPERTY(EditAnywhere, Category = "Grid")
	int Height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TSubclassOf<AActor> TileClass;
	//Functions

	UFUNCTION(BlueprintCallable, Category="Grid")
	bool SpawnTiles();

	UFUNCTION(BlueprintCallable, Category = "Grid")
	TArray<ATile_Base*> GetNeighbours(int GridX, int GridY, TArray<ATile_Base*> allTiles);

	UFUNCTION(BlueprintCallable, Category = "Grid")
	ATile_Base* FindTile(int GridX, int GridY, TArray<ATile_Base*> allTiles);	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
