
#include "RidingSystemStatus.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void URidingSystemStatus::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	UAttributeSet::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute()) {
		SetHealth(FMath::Clamp(GetHealth(), 0.000000f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetMaxHealthAttribute()) {
		SetMaxHealth(FMath::Clamp(GetMaxHealth(), 0.000000f, 100.000000f));
	}

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute()) {
		SetStamina(FMath::Clamp(GetStamina(), 0.000000f, GetMaxStamina()));
	}

	if (Data.EvaluatedData.Attribute == GetMaxStaminaAttribute()) {
		SetMaxStamina(FMath::Clamp(GetMaxStamina(), 0.000000f, 100.000000f));
	}

}


void URidingSystemStatus::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(URidingSystemStatus, Health, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URidingSystemStatus, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URidingSystemStatus, Stamina, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(URidingSystemStatus, MaxStamina, COND_None, REPNOTIFY_Always);

}


void URidingSystemStatus::OnRep_Health(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(URidingSystemStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(URidingSystemStatus, Health)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), Health, oldValue); 
}

void URidingSystemStatus::OnRep_MaxHealth(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(URidingSystemStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(URidingSystemStatus, MaxHealth)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), MaxHealth, oldValue); 
}

void URidingSystemStatus::OnRep_Stamina(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(URidingSystemStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(URidingSystemStatus, Stamina)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), Stamina, oldValue); 
}

void URidingSystemStatus::OnRep_MaxStamina(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(URidingSystemStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(URidingSystemStatus, MaxStamina)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), MaxStamina, oldValue); 
}


