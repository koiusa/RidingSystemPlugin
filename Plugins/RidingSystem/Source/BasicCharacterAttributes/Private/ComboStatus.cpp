
#include "ComboStatus.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void UComboStatus::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	UAttributeSet::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetCurrentComboCountAttribute()) {
		SetCurrentComboCount(FMath::Clamp(GetCurrentComboCount(), 0.000000f, 999999.f));
	}

	if (Data.EvaluatedData.Attribute == GetMaxComboCountAttribute()) {
		SetMaxComboCount(FMath::Clamp(GetMaxComboCount(), 0.000000f, 999999.f));
	}

	if (Data.EvaluatedData.Attribute == GetCurrentHitCountAttribute()) {
		SetCurrentHitCount(FMath::Clamp(GetCurrentHitCount(), 0.000000f, 999999.f));
	}

}


void UComboStatus::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UComboStatus, CurrentComboCount, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UComboStatus, MaxComboCount, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UComboStatus, CurrentHitCount, COND_None, REPNOTIFY_Always);

}


void UComboStatus::OnRep_CurrentComboCount(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UComboStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UComboStatus, CurrentComboCount)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), CurrentComboCount, oldValue); 
}

void UComboStatus::OnRep_MaxComboCount(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UComboStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UComboStatus, MaxComboCount)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), MaxComboCount, oldValue); 
}

void UComboStatus::OnRep_CurrentHitCount(const FGameplayAttributeData& oldValue)
{
	static FProperty* ThisProperty = FindFieldChecked<FProperty>(UComboStatus::StaticClass(), GET_MEMBER_NAME_CHECKED(UComboStatus, CurrentHitCount)); 
	GetTargetComponent()->SetBaseAttributeValueFromReplication(FGameplayAttribute(ThisProperty), CurrentHitCount, oldValue); 
}


