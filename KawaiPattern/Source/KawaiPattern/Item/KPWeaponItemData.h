// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/KPItemData.h"
#include "KPWeaponItemData.generated.h"

/**
 * 
 */
UCLASS()
class KAWAIPATTERN_API UKPWeaponItemData : public UKPItemData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = Weapon)
	TSoftObjectPtr<USkeletalMesh> WeaponMesh;
};
