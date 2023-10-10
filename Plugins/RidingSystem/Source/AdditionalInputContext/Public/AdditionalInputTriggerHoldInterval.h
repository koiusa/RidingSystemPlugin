#pragma once

#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "AdditionalInputTriggerHoldInterval.generated.h"

UCLASS(Abstract, Config = Input)
class UAdditionalInputTriggerTimedBase : public UInputTrigger
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite, Category = "Trigger Settings")
		float HeldDuration = 0.0f;

	virtual ETriggerState UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime) override;

public:

	virtual FString GetDebugState() const override { return HeldDuration ? FString::Printf(TEXT("Held:%.2f"), HeldDuration) : FString(); }
};


UCLASS(NotBlueprintable, meta = (DisplayName = "Hold And Accelerate"))
class UAdditionalInputTriggerHoldAndAccelaerate : public UAdditionalInputTriggerTimedBase
{
	GENERATED_BODY()

		bool bTriggered = false;

	float LastTriggerElapsedTime = 0.0f;

protected:

	virtual ETriggerState UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Config, BlueprintReadWrite, Category = "Trigger Settings")
		float HoldTimeThreshold = 0.5f;

	UPROPERTY(EditAnywhere, Config, BlueprintReadWrite, Category = "Trigger Settings")
		float MaxTriggerIntervalTime = 0.25f;

	UPROPERTY(EditAnywhere, Config, BlueprintReadWrite, Category = "Trigger Settings")
		float MinTriggerIntervalTime = 0.03f;

	UPROPERTY(EditAnywhere, Config, BlueprintReadWrite, Category = "Trigger Settings")
		float AccelerationTime = 2.0f;
};