// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/FlowNode_UpdateQuestStep.h"

#include "QuestSubsystem.h"

void UFlowNode_UpdateQuestStep::ExecuteInput(const FName& PinName)
{
	UQuestSubsystem* QuestSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UQuestSubsystem>();

	QuestSubsystem->UpdateQuestStep(Tag, Step);
	TriggerFirstOutput(true);
}

FText UFlowNode_UpdateQuestStep::GetNodeTitle() const
{
	return FText::FromString("Update Quest Step");
}

FString UFlowNode_UpdateQuestStep::GetNodeCategory() const
{
	return "Quest";
}
