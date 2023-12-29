// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "KPWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class KAWAIPATTERN_API UKPWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
protected:
	virtual void InitWidget() override;

};
