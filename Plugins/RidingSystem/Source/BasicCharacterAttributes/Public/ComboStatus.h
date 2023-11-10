
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "BasicAttributeSetMacros.h"
#include "ComboStatus.generated.h"
/**
 * 
 */
UCLASS()
class UComboStatus : public UAttributeSet
{
	GENERATED_BODY()
public:
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	UAbilitySystemComponent* GetTargetComponent() { if (mTargetComponent != nullptr) { return mTargetComponent; } mTargetComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(GetOwningActor(), true); return mTargetComponent; }

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_CurrentComboCount")
	FGameplayAttributeData CurrentComboCount{ 0.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UComboStatus, CurrentComboCount);
	UFUNCTION()
	virtual void OnRep_CurrentComboCount(const FGameplayAttributeData& OldValue);

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_MaxComboCount")
	FGameplayAttributeData MaxComboCount{ 3.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UComboStatus, MaxComboCount);
	UFUNCTION()
	virtual void OnRep_MaxComboCount(const FGameplayAttributeData& OldValue);

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_CurrentHitCount")
	FGameplayAttributeData CurrentHitCount{ 0.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UComboStatus, CurrentHitCount);
	UFUNCTION()
	virtual void OnRep_CurrentHitCount(const FGameplayAttributeData& OldValue);

private:
	UAbilitySystemComponent* mTargetComponent{ nullptr };
};
