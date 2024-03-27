// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile_Base.h"

// Sets default values
ATile_Base::ATile_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	gridPosX = -1;
	gridPosY = -1;
	isOccupied = false;
	TimeToOccupyAgain = 0;
	CanPlayerSpawn = false;
	StayTimer = 0;
}

void ATile_Base::SetTileSpawnable(bool _canPlayerSpawn)
{
	CanPlayerSpawn = _canPlayerSpawn;
}

void ATile_Base::SetTimer(float _time)
{
	TimeToOccupyAgain = _time;	
}

void ATile_Base::SetGridPos(int x, int y)
{
	gridPosX = x;
	gridPosY = y;
}

void ATile_Base::SetOccupied(bool occupied)
{
	isOccupied = occupied;
}

void ATile_Base::SetStayTimer(float _timer)
{
	StayTimer = _timer;
}

bool ATile_Base::GetTileSpawnable()
{
	return CanPlayerSpawn;
}

float ATile_Base::GetTimer()
{
	return TimeToOccupyAgain;
}

int ATile_Base::GetGridPosX()
{
	return gridPosX;
}

int ATile_Base::GetGridPosY()
{
	return gridPosY;
}

bool ATile_Base::GetOccupied()
{
	return isOccupied;
}

float ATile_Base::GetStayTimer()
{
	return StayTimer;
}

// Called when the game starts or when spawned
void ATile_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATile_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

