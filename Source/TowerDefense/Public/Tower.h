// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Queue.h"
#include "GameFramework/Pawn.h"
//#include "UObject/Function.h"
#include "Tower.generated.h"


UCLASS()
class TOWERDEFENSE_API ATower : public APawn
{
	GENERATED_BODY()		
public:	
	// Sets default values for this actor's properties
	ATower();		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
