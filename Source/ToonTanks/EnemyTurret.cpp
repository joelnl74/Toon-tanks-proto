// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTurret.h"
#include "PlayerTankPawn.h"
#include <Kismet/GameplayStatics.h>

void AEnemyTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playerTankPawn == nullptr)
	{
		return;
	}

	if (playerInRange())
	{
		RotateTurret(playerTankPawn->GetActorLocation());
	}
}

void AEnemyTurret::HandleOnDestroy()
{
	Super::HandleOnDestroy();

	Destroy();
}

void AEnemyTurret::BeginPlay()
{
	Super::BeginPlay();

	playerTankPawn = Cast<APlayerTankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(fireTimeHandle, this, &AEnemyTurret::CheckFireCondition, fireDelay, true);
}

void AEnemyTurret::CheckFireCondition()
{
	if (playerTankPawn == nullptr)
	{
		return;
	}

	if (playerInRange() && playerTankPawn->isAlive())
	{
		Fire();
	}
}

bool AEnemyTurret::playerInRange()
{
	float distance = FVector::Dist(GetActorLocation(), playerTankPawn->GetActorLocation());
	return distance < fireRange;
}
