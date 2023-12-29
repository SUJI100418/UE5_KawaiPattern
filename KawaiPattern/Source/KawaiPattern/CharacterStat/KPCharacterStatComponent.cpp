// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterStat/KPCharacterStatComponent.h"

// Sets default values for this component's properties
UKPCharacterStatComponent::UKPCharacterStatComponent()
{
	MaxHp = 200.0f;
	SetHp(MaxHp);
}


// Called when the game starts
void UKPCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	SetHp(MaxHp);
}

float UKPCharacterStatComponent::ApplyDamage(float InDamage)
{
	const float PrevHp = CurrentHp;
	const float ActualDamage = FMath::Clamp<float>(InDamage, 0, InDamage);

	SetHp(PrevHp - ActualDamage);
	if (CurrentHp <= KINDA_SMALL_NUMBER)
	{
		// Dead
		OnHpZero.Broadcast();
	}

	return ActualDamage;
}

void UKPCharacterStatComponent::SetHp(float NewHp)
{
	CurrentHp = FMath::Clamp<float>(NewHp, 0.0f, MaxHp);
	OnHpChanged.Broadcast(CurrentHp);
}


