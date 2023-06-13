// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AEnemyTank : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyTank();
	
protected:
	virtual void BeginPlay() override;

private:
	class APlayerTankPawn* playerTankPawn;
	class AAIController* AIController;
};
