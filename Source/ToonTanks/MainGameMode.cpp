// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include <Kismet/GameplayStatics.h>
#include "PlayerTankPawn.h"
#include "EnemyTurret.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	playerPawn = Cast<APlayerTankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AMainGameMode::ActorDied(AActor* deadActor)
{
	if (playerPawn == nullptr)
	{
		return;
	}

	if (deadActor == playerPawn)
	{
		playerPawn->HandleOnDestroy();
		playerPawn->DisableInput(playerPawn->GetPlayerController());
		playerPawn->GetPlayerController()->bShowMouseCursor = false;

		return;
	}

	if (AEnemyTurret* destroyedTurret = Cast<AEnemyTurret>(deadActor))
	{
		destroyedTurret->HandleOnDestroy();
	}


}


