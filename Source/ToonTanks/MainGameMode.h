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

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool wonGame);

private:
	void OnHandleStartPlay();
	int32 GetTargetTowerCount();

private:
	class APlayerTankPawn* playerPawn;
	class AMainPlayerController* mainPlayerController;

	UPROPERTY(EditAnywhere)
	float startDelay = 3.0f;

	int32 targetTowers = 0;
};
