
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "BasicAttributeSetMacros.h"
#include "MachineStatus.generated.h"
/**
 * 
 */
UCLASS()
class UMachineStatus : public UAttributeSet
{
	GENERATED_BODY()
public:
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	UAbilitySystemComponent* GetTargetComponent() { if (mTargetComponent != nullptr) { return mTargetComponent; } mTargetComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(GetOwningActor(), true); return mTargetComponent; }

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_Health")
	FGameplayAttributeData Health{ 100.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UMachineStatus, Health);
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue);

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_MaxHealth")
	FGameplayAttributeData MaxHealth{ 100.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UMachineStatus, MaxHealth);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_Energy")
	FGameplayAttributeData Energy{ 100.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UMachineStatus, Energy);
	UFUNCTION()
	virtual void OnRep_Energy(const FGameplayAttributeData& OldValue);

	UPROPERTY(Category = "GPAAttributes", EditAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRep_MaxEnergy")
	FGameplayAttributeData MaxEnergy{ 100.000000f };
	BASIC_ATTRIBUTE_ACCESSORS(UMachineStatus, MaxEnergy);
	UFUNCTION()
	virtual void OnRep_MaxEnergy(const FGameplayAttributeData& OldValue);

private:
	UAbilitySystemComponent* mTargetComponent{ nullptr };
};
