// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_DoesFactExist.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEMPLUGIN_API UFlowNode_DoesFactExist : public UFlowNode
{
	GENERATED_BODY()

protected:
	UFlowNode_DoesFactExist();
	
	UPROPERTY(EditAnywhere)
	FGameplayTag FactTag;
	
	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FText GetNodeTitle() const override;
	virtual FString GetNodeCategory() const override;
#endif
};
