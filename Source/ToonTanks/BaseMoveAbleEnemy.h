// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseMoveAbleEnemy.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ABaseMoveAbleEnemy : public AAIController
{
	GENERATED_BODY()
public:
	ABaseMoveAbleEnemy();

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

private:
	class APlayerTankPawn* playerTankPawn;
};
