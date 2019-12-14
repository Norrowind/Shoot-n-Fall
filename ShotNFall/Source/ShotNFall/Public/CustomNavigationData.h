// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomNavigationData.generated.h"

USTRUCT()
struct FPathNode
{
	GENERATED_USTRUCT_BODY()

	AActor* RepresentingActor;
	float G;
	float F;
	TArray<FPathNode*>NeighboorNodes;
};

UCLASS()
class SHOTNFALL_API ACustomNavigationData : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomNavigationData();

	static void BuildNavigationGraphNodesData(const TArray<AActor*>& PathPointsActors);

	static void BuildPath(TArray<AActor*>& PathPointsActors, AActor* Start, AActor* End);

	static float StraightDistance(FPathNode* From, FPathNode* To);

	static void ClearNavigationData();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	static TArray<FPathNode*>PathNodes;

	static FPathNode* FindNodeForActor(AActor* ActorToSearch);

	static FPathNode* FindNodeWithMinF(const TArray<FPathNode*>& PathPointsToSearchIn);

	static TArray<FPathNode*> FindUnclosedNeigboorNodes(const TArray<FPathNode*>& NeighboorNodes, const TArray<FPathNode*>& ClosedNodes);

	static bool FindPathWithAStarAlgorithm(FPathNode * StartNode, FPathNode * EndNode, TMap<FPathNode *, FPathNode *>& PathMap);

};
