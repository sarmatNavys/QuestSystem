// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void AddFact(const FGameplayTag& Tag, const int32 Value);

	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void IncrementFact(const FGameplayTag& Tag, const int32 Value);

	UFUNCTION(BlueprintCallable, Category = "Quest System")
	void RemoveFact(const FGameplayTag& Tag);

	UFUNCTION(BlueprintPure, Category = "Quest System")
	bool DoesFactExist(const FGameplayTag& Tag) const;

	UFUNCTION(BlueprintPure, Category = "Quest System")
	int32 GetFactValue(const FGameplayTag& Tag) const;
	
private:
	UPROPERTY()
	TMap<FGameplayTag, int32> Facts;
};
