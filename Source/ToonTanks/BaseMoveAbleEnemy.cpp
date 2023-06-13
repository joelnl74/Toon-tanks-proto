// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMoveAbleEnemy.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include "PlayerTankPawn.h"
#include <Kismet/GameplayStatics.h>

ABaseMoveAbleEnemy::ABaseMoveAbleEnemy()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseMoveAbleEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playerTankPawn == nullptr)
	{
		return;
	}

	MoveToActor(playerTankPawn, true, true, true);
}

void ABaseMoveAbleEnemy::BeginPlay()
{
	Super::BeginPlay();

	playerTankPawn = Cast<APlayerTankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}
