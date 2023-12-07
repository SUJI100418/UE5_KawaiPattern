// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KPPlayerController.h"

void AKPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}
