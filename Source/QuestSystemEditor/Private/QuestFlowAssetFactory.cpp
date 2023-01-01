// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestFlowAssetFactory.h"

#include "QuestFlowAsset.h"
#include "FlowEditor/Public/Graph/FlowGraph.h"

UQuestFlowAssetFactory::UQuestFlowAssetFactory()
{
	SupportedClass = UQuestFlowAsset::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}

UObject* UQuestFlowAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                                  UObject* Context, FFeedbackContext* Warn)
{
	UQuestFlowAsset* QuestFlowAsset = NewObject<UQuestFlowAsset>(InParent, InClass, InName, Flags | RF_Transactional);
	UFlowGraph::CreateGraph(QuestFlowAsset);
	
	return QuestFlowAsset;
}

FText UQuestFlowAssetFactory::GetDisplayName() const
{
	return FText::FromString("Quest Asset");
}
