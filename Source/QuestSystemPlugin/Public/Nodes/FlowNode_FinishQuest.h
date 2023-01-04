// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestFlowAsset.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_FinishQuest.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEMPLUGIN_API UFlowNode_FinishQuest : public UFlowNode
{
	GENERATED_BODY()

protected:
	virtual void ExecuteInput(const FName& PinName) override;

	UPROPERTY(EditAnywhere)
	FGameplayTag QuestTag;

	UPROPERTY(EditAnywhere)
	EQuestStatus QuestStatus;

#if WITH_EDITOR
	virtual FString GetNodeCategory() const override;
	virtual FText GetNodeTitle() const override;
#endif
};
