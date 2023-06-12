// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

void AMainPlayerController::SetPlayerControllerState(bool isEnabled)
{
	bShowMouseCursor = isEnabled;

	if (isEnabled)
	{
		GetPawn()->EnableInput(this);

		return;
	}

	GetPawn()->DisableInput(this);
}
