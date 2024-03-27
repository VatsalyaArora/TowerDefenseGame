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
	int y = 1;
	for (int x = 1; x <= Height * Width; x++)
	{
		
		if (Width % x)
		{
			y++;
		}
		//ATile_Base currentTile = ATile_Base();
		//currentTile.SetGridPos(x, y);
		//float xPos = ((x-1) * 100) - ((Width / 2) * 100);
		//float yPos = ((y-1) * 100) - ((Height / 2) * 100);
		//FVector Pos = { xPos,yPos,0 };
		//currentTile.SetActorLocation(Pos);
		
	}
	return false;
}

// Called when the game starts or when spawned
void AGrid_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrid_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

