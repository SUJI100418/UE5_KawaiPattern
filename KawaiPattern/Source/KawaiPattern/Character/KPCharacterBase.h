// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/KPAnimationAttackInterface.h"
#include "Interface/KPCharacterWidgetInterface.h"
#include "Interface/KPCharacterItemInterface.h"
#include "KPCharacterBase.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogKPCharacter, Log, All);

UENUM()
enum class ECharacterControlType : uint8
{
	Shoulder,
	Quater,
};

DECLARE_DELEGATE_OneParam(FOnTakeItemDelegate, class UKPItemData* /*InItemData*/);
USTRUCT(BlueprintType)
struct FTakeItemDelegateWrapper
{
	GENERATED_BODY()

	FTakeItemDelegateWrapper() {}
	FTakeItemDelegateWrapper(const FOnTakeItemDelegate& InItemDelegate) : ItemDelegate(InItemDelegate) {}
	FOnTakeItemDelegate ItemDelegate;
};

UCLASS()
class KAWAIPATTERN_API AKPCharacterBase : public ACharacter, public IKPAnimationAttackInterface, public IKPCharacterWidgetInterface, public IKPCharacterItemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKPCharacterBase();

	virtual void PostInitializeComponents() override;

protected:
	virtual void SetCharacterControlData(const class UKPCharacterControlData* CharacterControlData);

	UPROPERTY(EditAnywhere, Category = CharacterControl, Meta = (AllowPrivateAccess = "true"))
	TMap<ECharacterControlType, class UKPCharacterControlData*> CharacterControlManager;

// Combo Action Section
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	TObjectPtr<class UAnimMontage> ComboActionMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPriveAccess = "true"))
	TObjectPtr<class UKPComboActionData> ComboActionData;

	uint32 CurrentCombo = 0;
	FTimerHandle ComboTimerHandle;
	bool HasNextComboCommand = false;

	void ProcessComboCommand();

	void ComboActionBegin();
	void ComboActionEnd(class UAnimMontage* TargetMontage, bool IsProperlyEnded);
	void SetComboCheckTimer();
	void ComboCheck();

// Attack Hit Section
protected:
	virtual void AttackHitCheck() override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

// Dead Section
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAnimMontage> DeadMontage;

	virtual void SetDead();
	void PlayDeadAnimation();

	float DeadEventDelayTime = 5.0f;

// Stat Section
protected:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UKPCharacterStatComponent> Stat;

// UI Widget Section
protected:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Widget, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UKPWidgetComponent> HpBar;

	virtual void SetupCharacterWidget(class UKPUserWidget* InUserWidget) override;

// Item Section
protected:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Equipment, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TArray<FTakeItemDelegateWrapper> TakeItemActions;

	virtual void TakeItem(class UKPItemData* InItemData) override;
	virtual void DrinkPotion(class UKPItemData* InItemData);
	virtual void EquipWeapon(class UKPItemData* InItemData);
	virtual void ReadScroll(class UKPItemData* InItemData);
};
