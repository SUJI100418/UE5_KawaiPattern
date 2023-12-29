// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/KPCharacterBase.h"
#include "KPCharacterNonPlayer.generated.h"

/**
 * 
 */
UCLASS()
class KAWAIPATTERN_API AKPCharacterNonPlayer : public AKPCharacterBase
{
	GENERATED_BODY()
	
public:
	AKPCharacterNonPlayer();

protected:
	void SetDead() override;
};
