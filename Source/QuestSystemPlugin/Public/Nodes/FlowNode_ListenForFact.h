// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_ListenForFact.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEMPLUGIN_API UFlowNode_ListenForFact : public UFlowNode
{
	GENERATED_BODY()

protected:
	UFlowNode_ListenForFact();
	
	virtual void ExecuteInput(const FName& PinName) override;

	UPROPERTY()
	class UQuestSubsystem* QuestSubsystem;
	
	UPROPERTY(EditAnywhere)
	FGameplayTag Fact;

	UPROPERTY(EditAnywhere)
	int32 FactValue;

	UFUNCTION()
	void OnFactAdded(const FGameplayTag& Tag);

	UFUNCTION()
	void OnFactValueChanged(const FGameplayTag& Tag, const int32& Value);

#if WITH_EDITOR
	virtual FText GetNodeTitle() const override;
	virtual FString GetNodeCategory() const override;
	virtual FString GetNodeDescription() const override;
#endif
};
