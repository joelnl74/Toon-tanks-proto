// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include <Kismet/GameplayStatics.h>
#include "PlayerTankPawn.h"
#include "EnemyTurret.h"
#include "MainPlayerController.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	OnHandleStartPlay();
}

void AMainGameMode::OnHandleStartPlay()
{
	targetTowers = GetTargetTowerCount();

	playerPawn = Cast<APlayerTankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	mainPlayerController = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	mainPlayerController->SetPlayerControllerState(false);

	StartGame();

	FTimerHandle playerEnableTimerHandle;
	FTimerDelegate playerEnableTimerDelegate = FTimerDelegate::CreateUObject(
		mainPlayerController,
		&AMainPlayerController::SetPlayerControllerState,
		true
	);

	GetWorldTimerManager().SetTimer
	(
		playerEnableTimerHandle,
		playerEnableTimerDelegate,
		startDelay,
		false
	);
}

int32 AMainGameMode::GetTargetTowerCount()
{
	TArray<AActor*> towers;
	UGameplayStatics::GetAllActorsOfClass(this, AEnemyTurret::StaticClass(), towers);

	return towers.Num();
}

void AMainGameMode::ActorDied(AActor* deadActor)
{
	if (playerPawn == nullptr)
	{
		return;
	}

	if (mainPlayerController && deadActor == playerPawn)
	{
		playerPawn->HandleOnDestroy();
		mainPlayerController->SetPlayerControllerState(false);

		GameOver(false);

		return;
	}

	if (AEnemyTurret* destroyedTurret = Cast<AEnemyTurret>(deadActor))
	{
		destroyedTurret->HandleOnDestroy();
		--targetTowers;
	}

	if (targetTowers <= 0)
	{
		GameOver(true);
	}
}
