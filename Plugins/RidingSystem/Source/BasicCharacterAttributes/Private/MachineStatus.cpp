
#include "MachineStatus.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void UMachineStatus::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	UAttributeSet::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute()) {
		SetHealth(FMath::Clamp(GetHealth(), 0.000000f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute()) {
		SetMaxHealth(FMath::Clamp(GetMaxHealth(), 0.000000f, 100.000000f));
	}

	if (Data.EvaluatedData.Attribute == GetEnergyAttribute()) {
		SetEnergy(FMath::Clamp(GetEnergy(), 0.000000f, GetMaxEnergy()));
	}

	if (Data.EvaluatedData.Attribute == GetMaxEnergyAttribute()) {
		SetMaxEnergy(FMath::Clamp(GetMaxEnergy(), 0.000000f, 100.000000f));
	}

}


void UMachineStatus::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UMachineStatus, Health, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UMachineStatus, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UMachineStatus, Energy, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UMachineStatus, MaxEnergy, COND_None, REPNOTIFY_Always);

}


void UMachineStatus::OnRep_Health(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UMachineStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UMachineStatus, Health)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), Health, oldValue); 
}

void UMachineStatus::OnRep_MaxHealth(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UMachineStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UMachineStatus, MaxHealth)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), MaxHealth, oldValue); 
}

void UMachineStatus::OnRep_Energy(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UMachineStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UMachineStatus, Energy)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), Energy, oldValue); 
}

void UMachineStatus::OnRep_MaxEnergy(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UMachineStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UMachineStatus, MaxEnergy)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), MaxEnergy, oldValue); 
}


