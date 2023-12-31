// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TimerManager.h"
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

	void HandleOnDestroy();

protected:
	virtual void BeginPlay() override;

private:
	void CheckFireCondition();
	bool playerInRange();

private:
	class APlayerTankPawn* playerTankPawn;
	
	UPROPERTY(EditAnywhere, Category="Parameters")
	float fireRange = 400;

	UPROPERTY(EditAnywhere, Category="Parameters")
	float fireDelay = 2;

	FTimerHandle fireTimeHandle;
};
