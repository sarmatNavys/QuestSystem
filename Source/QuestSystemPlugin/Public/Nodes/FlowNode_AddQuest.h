// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_AddQuest.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEMPLUGIN_API UFlowNode_AddQuest : public UFlowNode
{
	GENERATED_BODY()

protected:
	virtual void ExecuteInput(const FName& PinName) override;

	UPROPERTY(EditAnywhere)
	class UQuestFlowAsset* QuestFlowAsset;

	UPROPERTY(EditAnywhere)
	FGameplayTag Tag;

#if WITH_EDITOR
	virtual FString GetNodeCategory() const override;
	virtual FText GetNodeTitle() const override;
#endif
	
};
