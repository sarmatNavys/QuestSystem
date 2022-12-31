// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestFlowAsset.h"
#include "QuestSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFactAdded, const FGameplayTag&, Fact);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFactRemoved, const FGameplayTag&, Fact);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFactValueChanged, const FGameplayTag&, Fact, const int32&, Value);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestAdded, const FGameplayTag&, Quest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestStepUpdated, const FGameplayTag&, Quest, const FQuestStep&, Step);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestCompleted, const FGameplayTag&, Quest, EQuestStatus, Status);

/**
 Quest subsystem. Controls all Quest and Facts logic. 
 */
UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	/** Add fact to database. Pre-checks, does fact exist. */
	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void AddFact(const FGameplayTag& Tag, const int32 Value);

	/** Increment's fact value. Pre-checks, does fact exist. */
	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void IncrementFact(const FGameplayTag& Tag, const int32 Value);

	/** Remove fact from database. Pre-checks, does fact exist. */
	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void RemoveFact(const FGameplayTag& Tag);

	/** Checks quest is valid in database. */
	UFUNCTION(BlueprintPure, Category = "Quest System")
	bool DoesFactExist(const FGameplayTag& Tag) const;

	/** Returns fact value from database. If fact does not exist returns 0. */
	UFUNCTION(BlueprintPure, Category = "Quest System")
	int32 GetFactValue(const FGameplayTag& Tag) const;

	UPROPERTY(BlueprintAssignable, Category = "Quest System")
	FOnFactAdded OnFactAdded;

	UPROPERTY(BlueprintAssignable, Category = "Quest System")
	FOnFactRemoved OnFactRemoved;

	UPROPERTY(BlueprintAssignable, Category = "Quest System")
	FOnFactValueChanged OnFactValueChanged;

	/** Add quest to database. Pre-checks, does quest exits. */
	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void AddQuest(const FGameplayTag& Tag, UQuestFlowAsset* Quest);

	/** Update quest step in database. Pre-checks, does quest exits. */
	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void UpdateQuestStep(const FGameplayTag& Tag, const FQuestStep& NewStep);

	/** Complete quest in database. Pre-checks, does quest exits. */
	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void CompleteQuest(const FGameplayTag& Tag, EQuestStatus CompleteStatus);

	/** Checks, does quest valid and exist in database. */
	UFUNCTION(BlueprintCallable, Category = "Quest System")
	bool DoesQuestExist(const FGameplayTag& Tag) const;

	UPROPERTY(BlueprintAssignable, Category = "Quest System")
	FOnQuestAdded OnQuestAdded;

	UPROPERTY(BlueprintAssignable, Category = "Quest System")
	FOnQuestStepUpdated OnQuestStepUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Quest System")
	FOnQuestCompleted OnQuestCompleted;
	
private:

	/** Facts DB. */
	UPROPERTY()
	TMap<FGameplayTag, int32> Facts;

	/** Quests DB. */
	UPROPERTY()
	TMap<FGameplayTag, UQuestFlowAsset*> Quests;
};
