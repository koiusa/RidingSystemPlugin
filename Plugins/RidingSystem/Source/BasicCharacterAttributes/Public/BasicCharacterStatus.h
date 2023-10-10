
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "BasicAttributeSetMacros.h"
#include "BasicCharacterStatus.generated.h"
/**
 * 
 */
UCLASS()
class UBasicCharacterStatus : public UAttributeSet
{
	GENERATED_BODY()
public:
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	UAbilitySystemComponent* GetTargetComponent() { if (mTargetComponent != nullptr) { return mTargetComponent; } mTargetComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(GetOwningActor(), true); return mTargetComponent; }

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_Health")
	FGameplayAttributeData Health{ 100.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UBasicCharacterStatus, Health);
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue);

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_MaxHealth")
	FGameplayAttributeData MaxHealth{ 100.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UBasicCharacterStatus, MaxHealth);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_Stamina")
	FGameplayAttributeData Stamina{ 100.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UBasicCharacterStatus, Stamina);
	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldValue);

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_MaxStamina")
	FGameplayAttributeData MaxStamina{ 100.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UBasicCharacterStatus, MaxStamina);
	UFUNCTION()
	virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldValue);

private:
	UAbilitySystemComponent* mTargetComponent{ nullptr };
};
