// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "QuestFlowAsset.generated.h"

UENUM(BlueprintType)
enum class EQuestStatus : uint8
{
	Active,
	Failed,
	Completed
};

/** Contains Quest Step Information. */
USTRUCT(BlueprintType)
struct FQuestStep
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest System")
	FText Target;
};

/**
   Quest Asset. Contains quest information. 
 */
UCLASS()
class QUESTSYSTEMPLUGIN_API UQuestFlowAsset : public UFlowAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest System")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest System")
	FQuestStep CurrentStep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest System")
	EQuestStatus QuestStatus;
};
