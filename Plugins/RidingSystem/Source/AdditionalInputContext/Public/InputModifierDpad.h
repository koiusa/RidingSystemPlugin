// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputModifiers.h"
#include "InputModifierDpad.generated.h"

/**
 * 
 */
UCLASS(NotBlueprintable, MinimalAPI, meta = (DisplayName = "Dpad Input Axis Values"))
class UInputModifierDpad : public UInputModifier
{
	GENERATED_BODY()

protected:
	virtual FInputActionValue ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime) override;
};
