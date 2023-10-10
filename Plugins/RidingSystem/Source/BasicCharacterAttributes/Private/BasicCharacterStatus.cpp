
#include "BasicCharacterStatus.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void UBasicCharacterStatus::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
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


void UBasicCharacterStatus::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UBasicCharacterStatus, Health, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBasicCharacterStatus, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBasicCharacterStatus, Stamina, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UBasicCharacterStatus, MaxStamina, COND_None, REPNOTIFY_Always);

}


void UBasicCharacterStatus::OnRep_Health(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UBasicCharacterStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UBasicCharacterStatus, Health)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), Health, oldValue); 
}

void UBasicCharacterStatus::OnRep_MaxHealth(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UBasicCharacterStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UBasicCharacterStatus, MaxHealth)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), MaxHealth, oldValue); 
}

void UBasicCharacterStatus::OnRep_Stamina(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UBasicCharacterStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UBasicCharacterStatus, Stamina)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), Stamina, oldValue); 
}

void UBasicCharacterStatus::OnRep_MaxStamina(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UBasicCharacterStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UBasicCharacterStatus, MaxStamina)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), MaxStamina, oldValue); 
}


