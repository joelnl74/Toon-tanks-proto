// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTank.h"
#include "PlayerTankPawn.h"
#include <Kismet/GameplayStatics.h>
#include "AIController.h"

AEnemyTank::AEnemyTank()
{
}

void AEnemyTank::BeginPlay()
{
	Super::BeginPlay();

	AIController = Cast<AAIController>(GetController());
	playerTankPawn = Cast<APlayerTankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	this->bUseControllerRotationYaw = false;

	if (playerTankPawn == nullptr)
	{
		return;
	}

	AIController->MoveToActor(playerTankPawn, true, true, true);
}
