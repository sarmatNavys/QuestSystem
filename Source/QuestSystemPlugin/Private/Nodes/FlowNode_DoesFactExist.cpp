// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/FlowNode_DoesFactExist.h"

#include "QuestSubsystem.h"

UFlowNode_DoesFactExist::UFlowNode_DoesFactExist()
{
	OutputPins.Empty();

	OutputPins.Add(FFlowPin(TEXT("Exist")));
	OutputPins.Add(FFlowPin(TEXT("Not Exist")));
}

void UFlowNode_DoesFactExist::ExecuteInput(const FName& PinName)
{
	const UQuestSubsystem* QuestSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UQuestSubsystem>();

	if (QuestSubsystem->DoesFactExist(FactTag))
	{
		TriggerOutput(TEXT("Exist"), true);
	}

	else
	{
		TriggerOutput(TEXT("Not Exist"), true);
	}
}

FText UFlowNode_DoesFactExist::GetNodeTitle() const
{
	return FText::FromString("Does Fact Exist");
}

FString UFlowNode_DoesFactExist::GetNodeCategory() const
{
	return "Quest";
}
