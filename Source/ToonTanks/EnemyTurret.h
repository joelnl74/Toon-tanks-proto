// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnemyTurret.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AEnemyTurret : public ABasePawn
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	class APlayerTankPawn* playerTankPawn;
	
	UPROPERTY(EditAnywhere, Category="Parameters")
	float fireRange = 400;
};
