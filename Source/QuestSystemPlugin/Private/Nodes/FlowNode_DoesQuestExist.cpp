// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/FlowNode_DoesQuestExist.h"

#include "QuestSubsystem.h"

UFlowNode_DoesQuestExist::UFlowNode_DoesQuestExist()
{
	OutputPins.Empty();

	OutputPins.Add(FFlowPin(TEXT("Exist")));
	OutputPins.Add(FFlowPin(TEXT("Not Exist")));
}

void UFlowNode_DoesQuestExist::ExecuteInput(const FName& PinName)
{
	const UQuestSubsystem* QuestSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UQuestSubsystem>();

	if (QuestSubsystem->DoesQuestExist(QuestTag))
	{
		TriggerOutput(TEXT("Exist"), true);
	}

	else
	{
		TriggerOutput(TEXT("Not Exist"), true);
	}
}

FText UFlowNode_DoesQuestExist::GetNodeTitle() const
{
	return FText::FromString("Does Quest Exist");
}

FString UFlowNode_DoesQuestExist::GetNodeCategory() const
{
	return "Quest";
}
