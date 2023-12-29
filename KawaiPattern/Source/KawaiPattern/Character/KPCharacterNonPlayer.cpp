// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/KPCharacterNonPlayer.h"

AKPCharacterNonPlayer::AKPCharacterNonPlayer()
{
}

void AKPCharacterNonPlayer::SetDead()
{
	Super::SetDead();

	FTimerHandle DeadTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda(
		[&]()
		{
			Destroy();
		}), DeadEventDelayTime, false);
}
