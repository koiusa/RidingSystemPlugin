// Fill out your copyright notice in the Description page of Project Settings.


#include "InputModifierDpad.h"

FInputActionValue UInputModifierDpad::ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime)
{
	FVector userinput = CurrentValue.Get<FVector>();
	int value = trunc(userinput.Y * 100)/14;
	FVector2D ActionValue = FVector2D(0, 0);
	FInputActionValue ReturnValue = FInputActionValue(ActionValue);
	switch (value)
	{
	case 0:
		ActionValue = FVector2D(0, 1);
		ReturnValue = FInputActionValue(ActionValue);
		break;
	case 1:
		ActionValue = FVector2D(1, 1);
		ActionValue.Normalize();
		ReturnValue = FInputActionValue(ActionValue);
		break;
	case 2:
		ActionValue = FVector2D(1, 0);
		ReturnValue = FInputActionValue(ActionValue);
		break;
	case 3:
		ActionValue = FVector2D(1, -1);
		ActionValue.Normalize();
		ReturnValue = FInputActionValue(ActionValue);
		break;

	case 4:
		ActionValue = FVector2D(0, -1);
		ReturnValue = FInputActionValue(ActionValue);
		break;
	case 5:
		ActionValue = FVector2D(-1, -1);
		ActionValue.Normalize();
		ReturnValue = FInputActionValue(ActionValue);
		break;
	case 6:
		ActionValue = FVector2D(-1, 0);
		ReturnValue = FInputActionValue(ActionValue);
		break;
	case 7:
		ActionValue = FVector2D(-1, 1);
		ActionValue.Normalize();
		ReturnValue = FInputActionValue(ActionValue);
		break;
	case 8:
	default:
		break;
	}
	return ReturnValue;
}
