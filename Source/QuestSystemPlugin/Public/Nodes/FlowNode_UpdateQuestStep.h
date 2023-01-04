// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestFlowAsset.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_UpdateQuestStep.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEMPLUGIN_API UFlowNode_UpdateQuestStep : public UFlowNode
{
	GENERATED_BODY()

protected:
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere)
	FQuestStep Step;

	UPROPERTY(EditAnywhere)
	FGameplayTag Tag;

#if WITH_EDITOR
	virtual FText GetNodeTitle() const override;
	virtual FString GetNodeCategory() const override;
#endif
};
