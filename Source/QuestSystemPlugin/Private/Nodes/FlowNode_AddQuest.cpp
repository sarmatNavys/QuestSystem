// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/FlowNode_AddQuest.h"

#include "QuestSubsystem.h"

void UFlowNode_AddQuest::ExecuteInput(const FName& PinName)
{
	UQuestSubsystem* QuestSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UQuestSubsystem>();
	
	QuestSubsystem->AddQuest(Tag, QuestFlowAsset);
	TriggerFirstOutput(true);
}

FString UFlowNode_AddQuest::GetNodeCategory() const
{
	return "Quest";
}

FText UFlowNode_AddQuest::GetNodeTitle() const
{
	return FText::FromString("Add Quest");
}
