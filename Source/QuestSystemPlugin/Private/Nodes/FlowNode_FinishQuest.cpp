// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/FlowNode_FinishQuest.h"

#include "QuestSubsystem.h"

void UFlowNode_FinishQuest::ExecuteInput(const FName& PinName)
{
	UQuestSubsystem* QuestSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UQuestSubsystem>();

	QuestSubsystem->CompleteQuest(QuestTag, QuestStatus);
	TriggerFirstOutput(true);
}

FString UFlowNode_FinishQuest::GetNodeCategory() const
{
	return "Quest";
}

FText UFlowNode_FinishQuest::GetNodeTitle() const
{
	return FText::FromString("Finish Quest");
}
