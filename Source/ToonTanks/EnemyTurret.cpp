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

	float distance = FVector::Dist(GetActorLocation(), playerTankPawn->GetActorLocation());

	if (distance < fireRange)
	{
		RotateTurret(playerTankPawn->GetActorLocation());
	}
}

void AEnemyTurret::BeginPlay()
{
	Super::BeginPlay();

	playerTankPawn = Cast<APlayerTankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}
