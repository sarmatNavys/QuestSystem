// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/FlowNode_ListenForFact.h"

#include "QuestSubsystem.h"

UFlowNode_ListenForFact::UFlowNode_ListenForFact()
{
	OutputPins.Empty();

	OutputPins.Add(FFlowPin(TEXT("Continue")));
	OutputPins.Add(FFlowPin(TEXT("Fact Received")));

	QuestSubsystem = nullptr;
}

void UFlowNode_ListenForFact::ExecuteInput(const FName& PinName)
{
	QuestSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UQuestSubsystem>();

	QuestSubsystem->OnFactAdded.AddUniqueDynamic(this, &UFlowNode_ListenForFact::OnFactAdded);
	QuestSubsystem->OnFactValueChanged.AddUniqueDynamic(this, &UFlowNode_ListenForFact::OnFactValueChanged);

	TriggerOutput(TEXT("Continue"));
}

void UFlowNode_ListenForFact::OnFactAdded(const FGameplayTag& Tag)
{
	if (Fact == Tag)
	{
		if (QuestSubsystem->GetFactValue(Fact) == FactValue)
		{
			TriggerOutput(TEXT("Fact Received"), true);
			QuestSubsystem->OnFactAdded.RemoveDynamic(this, &UFlowNode_ListenForFact::OnFactAdded);
		}
	}
}

void UFlowNode_ListenForFact::OnFactValueChanged(const FGameplayTag& Tag, const int32& Value)
{
	if (Fact == Tag && Value == FactValue)
	{
		TriggerOutput(TEXT("Fact Received"), true);
		QuestSubsystem->OnFactValueChanged.RemoveDynamic(this, &UFlowNode_ListenForFact::OnFactValueChanged);
	}
}

FText UFlowNode_ListenForFact::GetNodeTitle() const
{
	return FText::FromString("Listen for Fact");
}

FString UFlowNode_ListenForFact::GetNodeCategory() const
{
	return "Quest";
}

FString UFlowNode_ListenForFact::GetNodeDescription() const
{
	return "Listen's for fact.";
}
