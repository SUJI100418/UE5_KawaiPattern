// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KPUserWidget.h"
#include "KPHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class KAWAIPATTERN_API UKPHpBarWidget : public UKPUserWidget
{
	GENERATED_BODY()

public:
	UKPHpBarWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

public:
	FORCEINLINE void SetMaxHp(float NewMaxHp) { MaxHp = NewMaxHp; }
	void UpdateHpBar(float NewCurrentHp);

protected:
	UPROPERTY()
	TObjectPtr<class UProgressBar> HpProgressBar;

	UPROPERTY()
	float MaxHp;
	
};
