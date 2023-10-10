
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define BASIC_GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) 	static FGameplayAttribute Get##PropertyName##Attribute() 	{ 		static FProperty* Prop = FindFieldChecked<FProperty>(ClassName::StaticClass(), GET_MEMBER_NAME_CHECKED(ClassName, PropertyName)); 		return Prop; 	}

#define BASIC_GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) 	FORCEINLINE float Get##PropertyName() const 	{ 		return PropertyName.GetCurrentValue(); 	}

#define BASIC_GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) 	FORCEINLINE void Set##PropertyName(float NewVal) 	{ 		UAbilitySystemComponent* AbilityComp = GetTargetComponent(); 		if (ensure(AbilityComp)) 		{ 			AbilityComp->SetNumericAttributeBase(Get##PropertyName##Attribute(), NewVal); 		}; 	}

#define BASIC_GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) 	FORCEINLINE void Init##PropertyName(float NewVal) 	{ 		PropertyName.SetBaseValue(NewVal); 		PropertyName.SetCurrentValue(NewVal); 	}

#define BASIC_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) 	BASIC_GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) 	BASIC_GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) 	BASIC_GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) 	BASIC_GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
