// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSubsystem.h"

#include "FlowSubsystem.h"
#include "QuestSystemPlugin.h"
#include "Engine/World.h"

void UQuestSubsystem::AddFact(const FGameplayTag& Tag, const int32 Value)
{
	if (DoesFactExist(Tag))
	{
		UE_LOG(LogQuestSystemPlugin, Warning, TEXT("Can't add fact %s. This Fact Already Exist in Database"), *Tag.ToString());
		return;
	}
	
	Facts.Add(Tag, Value);
}

void UQuestSubsystem::IncrementFact(const FGameplayTag& Tag, const int32 Value)
{
	if (!DoesFactExist(Tag))
	{
		UE_LOG(LogQuestSystemPlugin, Warning, TEXT("Can't increment fact %s. This Fact does not exist in database"), *Tag.ToString());
		return;
	}

	Facts[Tag] += Value;
}

void UQuestSubsystem::RemoveFact(const FGameplayTag& Tag)
{
	if (!DoesFactExist(Tag))
	{
		UE_LOG(LogQuestSystemPlugin, Warning, TEXT("Can't remove fact %s. This fact does not exist in database"), *Tag.ToString());
		return;
	}

	Facts.Remove(Tag);
}

bool UQuestSubsystem::DoesFactExist(const FGameplayTag& Tag) const
{
	return Facts.Contains(Tag);
}

int32 UQuestSubsystem::GetFactValue(const FGameplayTag& Tag) const
{
	if (!DoesFactExist(Tag))
	{
		UE_LOG(LogQuestSystemPlugin, Warning, TEXT("Cannot get value of %s fact. It does not exist in database"), *Tag.ToString());
		return 0;
	}

	return Facts[Tag];
}

void UQuestSubsystem::AddQuest(const FGameplayTag& Tag, UQuestFlowAsset* Quest)
{
	UFlowSubsystem* FlowSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UFlowSubsystem>();
	
	if (DoesQuestExist(Tag))
	{
		UE_LOG(LogQuestSystemPlugin, Warning, TEXT("Quest %s already exist in database."), *Tag.ToString());
		return;
	}

	Quests.Add(Tag, Quest);
	FlowSubsystem->StartRootFlow(Quest, Quest);
	OnQuestAdded.Broadcast(Tag);
}

void UQuestSubsystem::UpdateQuestStep(const FGameplayTag& Tag, const FQuestStep& NewStep)
{
	if (!DoesQuestExist(Tag))
	{
		UE_LOG(LogQuestSystemPlugin, Warning, TEXT("Can't update quest step. Quest %s does not exist in database"), *Tag.ToString());
		return;
	}

	Quests[Tag]->CurrentStep = NewStep;
	OnQuestStepUpdated.Broadcast(Tag, NewStep);
}

void UQuestSubsystem::CompleteQuest(const FGameplayTag& Tag, EQuestStatus CompleteStatus)
{
	if (!DoesQuestExist(Tag))
	{
		UE_LOG(LogQuestSystemPlugin, Warning, TEXT("Can't complete quest. Quest %s does not exist in database"), *Tag.ToString());
		return;
	}

	Quests[Tag]->QuestStatus = CompleteStatus;
	Quests[Tag]->FinishFlow(EFlowFinishPolicy::Abort);
	OnQuestCompleted.Broadcast(Tag, CompleteStatus);
}

bool UQuestSubsystem::DoesQuestExist(const FGameplayTag& Tag) const
{
	return Quests.Contains(Tag);
}