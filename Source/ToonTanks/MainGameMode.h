// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	void ActorDied(AActor* deadActor);

protected:
	virtual void BeginPlay() override;

private:
	class APlayerTankPawn* playerPawn;
};
