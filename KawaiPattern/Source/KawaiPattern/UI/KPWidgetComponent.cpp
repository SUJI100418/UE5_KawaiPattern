// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/KPWidgetComponent.h"
#include "KPUserWidget.h"

void UKPWidgetComponent::InitWidget()
{
	Super::InitWidget();

	UKPUserWidget* KPUserWidget = Cast<UKPUserWidget>(GetWidget());
	if (KPUserWidget)
	{
		KPUserWidget->SetOwningActor(GetOwner());
	}
}