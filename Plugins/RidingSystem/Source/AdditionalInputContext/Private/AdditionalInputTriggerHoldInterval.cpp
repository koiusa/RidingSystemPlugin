#include "AdditionalInputTriggerHoldInterval.h"
#include "Kismet/KismetMathLibrary.h"

ETriggerState UAdditionalInputTriggerTimedBase::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime)
{
	ETriggerState State = ETriggerState::None;

	// Transition to Ongoing on actuation.
	if (IsActuated(ModifiedValue))
	{
		State = ETriggerState::Ongoing;
		HeldDuration += DeltaTime;	// TODO: When attached directly to an Action this will tick N times a frame where N is the number of evaluated (actively held) mappings.
	}
	else
	{
		// Reset duration
		HeldDuration = 0.0f;
	}

	return State;
}

ETriggerState UAdditionalInputTriggerHoldAndAccelaerate::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime)
{
	ETriggerState State = Super::UpdateState_Implementation(PlayerInput, ModifiedValue, DeltaTime);

	float Alpha = FMath::Clamp(HeldDuration - HoldTimeThreshold, 0, AccelerationTime) / AccelerationTime;
	float TriggerInterval = FMath::Lerp(MaxTriggerIntervalTime, MinTriggerIntervalTime, Alpha);

	bTriggered = (HeldDuration >= HoldTimeThreshold) && (LastTriggerElapsedTime >= TriggerInterval);
	if (bTriggered)
	{
		LastTriggerElapsedTime = 0.0f;
		return ETriggerState::Triggered;
	}

	LastTriggerElapsedTime = LastTriggerElapsedTime + DeltaTime;

	return State;
}
