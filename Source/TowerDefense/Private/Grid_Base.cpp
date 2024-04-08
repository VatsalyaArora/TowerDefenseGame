// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid_Base.h"

// Sets default values
AGrid_Base::AGrid_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool AGrid_Base::SpawnTiles()
{
	int y = 0;
	int x = 0;
	UWorld* world = GetWorld();
	FTransform transform = FTransform();
	FActorSpawnParameters spawnParameters;	
	if (IsValid(world))
	{
		for (int i = 1; i <= Height * Width; i++)
		{
			if (i%Width == 1)
			{
				x = 1;
				y++;
			}
			float XPos = 0;
			XPos = (x - (Width / 2)) * 100;
			float YPos = 0;
			YPos = (y - (Height / 2)) * 100;
			transform.SetLocation({  XPos, YPos, 0.5f });
			transform.SetRotation({ 0,0,0,0 });
			transform.SetScale3D({ 1, 1, 1 });
			AActor* tile = world->SpawnActor<AActor>(TileClass, transform);
			ATile_Base* spawnedTile = Cast<ATile_Base>(tile);
			spawnedTile->SetGridPos(x, y);
			x++;
		}
	}
	return false;
}

TArray<ATile_Base*> AGrid_Base::GetNeighbours(int GridX, int GridY, TArray<ATile_Base*> allTiles)
{
	TArray<ATile_Base*> neighbours;
	if (GridX == 0 || GridY == 0)
		return neighbours;
	int neighboursSize = 9;
	int x = -1;
	int y = -2;
	for (int i = 0; i < neighboursSize; i++)
	{
		if (i % 3 == 0)
		{
			x = -1;
			y++;
		}
		if (x + GridX >= 1 && y + GridY >= 1 && GridX + x <= Width && y + GridY <= Height)
		{
			if (x != 0 || y != 0)
			{
				ATile_Base* currentNeighbour = FindTile(x + GridX, y + GridY, allTiles);
				neighbours.Add(currentNeighbour);
			}
		}
		x++;
	}
	return neighbours;
}

ATile_Base* AGrid_Base::FindTile(int GridX, int GridY, TArray<ATile_Base*> allTiles)
{
	int i = 0;
	

	while (true)
	{

		if (allTiles[i]->GetGridPosY() == GridY)
		{
			if (allTiles[i]->GetGridPosX() == GridX)
			{
				break;
			}
			else
			{
				i++;
			}
		}
		else
		{
			i += Width;
		}
	}
	return allTiles[i];	
}



// Called when the game starts or when spawned
void AGrid_Base::BeginPlay()
{
	Super::BeginPlay();

	//SpawnTiles();
	
}

// Called every frame
void AGrid_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

