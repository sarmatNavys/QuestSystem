// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSubsystem.h"
#include "QuestSystemPlugin.h"

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
