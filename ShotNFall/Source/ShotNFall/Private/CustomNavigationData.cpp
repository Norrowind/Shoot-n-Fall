// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/CustomNavigationData.h"
#include "Components/CapsuleComponent.h"

TArray<FPathNode*> ACustomNavigationData::PathNodes;

// Sets default values
ACustomNavigationData::ACustomNavigationData()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACustomNavigationData::BeginPlay()
{
	Super::BeginPlay();
	
}

//Get all platforms on the level to build the graph data
void ACustomNavigationData::BuildNavigationGraphNodesData(const TArray<AActor*>& PathPointsActors)
{

	TSubclassOf<UCapsuleComponent>NavigationCapsuleClass = UCapsuleComponent::StaticClass();

	//Creating Path Nodes pool 
	for (auto ActorToGetData : PathPointsActors)
	{
		FPathNode* PathNode = new FPathNode();
		PathNode->RepresentingActor = ActorToGetData;
		PathNodes.Push(PathNode);
	}
	
	//Set the nodes neighboors for every node 
	for (auto PathNode : PathNodes)
	{
		TArray<UActorComponent*> NavigationCapsules = PathNode->RepresentingActor->GetComponentsByClass(NavigationCapsuleClass);
		TArray<AActor*>NeighboorActors;

		//get all actors which are overlapped by capsules component of platform
		for (auto RawCapsule : NavigationCapsules)
		{
			UCapsuleComponent* Capsule = Cast<UCapsuleComponent>(RawCapsule);
			if (Capsule)
			{
				TArray<AActor*>ActorsOfEachCapsule;
				Capsule->GetOverlappingActors(ActorsOfEachCapsule);
				NeighboorActors += ActorsOfEachCapsule;
				Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			}
			
		}

		//for every neighboor actor - find node in path nodes pool
		for (auto Neighboor : NeighboorActors)
		{
			FPathNode* NeighboorNode = FindNodeForActor(Neighboor);
			if (NeighboorNode)
			{
				PathNode->NeighboorNodes.Push(NeighboorNode);
			}
		}
	}
}

//clear data - called in game mode EndPlay
void ACustomNavigationData::ClearNavigationData()
{
	for (auto PathNode : PathNodes)
	{
		delete PathNode;
	}
	PathNodes.Empty();
}


FPathNode* ACustomNavigationData::FindNodeForActor(AActor* ActorToSearch)
{
	FPathNode** PathNode = PathNodes.FindByPredicate([ActorToSearch](FPathNode* NodeToSearch) {return NodeToSearch->RepresentingActor == ActorToSearch; });
	if (PathNode)
	{
		return *PathNode;
	}
	else
	{
		return nullptr;
	}
}

//Convert found path into array of actors chich AI character will use to move to
void ACustomNavigationData::BuildPath(TArray<AActor*>& PathPointsActors, AActor* Start, AActor* End)
{
	TMap<FPathNode*, FPathNode*>PathMap;
	FPathNode* StartNode = FindNodeForActor(Start);
	FPathNode* EndNode = FindNodeForActor(End);
	bool IsPathValid = FindPathWithAStarAlgorithm(StartNode, EndNode, PathMap);
	if (IsPathValid)
	{
		TArray<AActor*>TempPathPointsActors;
		TempPathPointsActors.Add(EndNode->RepresentingActor);
		FPathNode* PathMapIterator = EndNode;
		while (PathMapIterator != StartNode)
		{
			FPathNode* CurrentNode = PathMap[PathMapIterator];
			TempPathPointsActors.Add(CurrentNode->RepresentingActor);
			PathMapIterator = CurrentNode;
		}
		for (int32 i = TempPathPointsActors.Num() - 1; i >= 0; i--)
		{
			PathPointsActors.Add(TempPathPointsActors[i]);
		}
	}
}

//make the shortest path using A* algorith
bool ACustomNavigationData::FindPathWithAStarAlgorithm(FPathNode * StartNode, FPathNode * EndNode, TMap<FPathNode *, FPathNode *> &PathMap)
{
	TArray<FPathNode*>ClosedNodes;
	TArray<FPathNode*>OpenNodes;
	OpenNodes.Add(StartNode);

	StartNode->G = 0;
	StartNode->F = StartNode->G + StraightDistance(StartNode, EndNode);
	while (OpenNodes.Num() > 0)
	{
		FPathNode* CurrentNode = FindNodeWithMinF(OpenNodes);
		if (CurrentNode == EndNode) { return true; }

		OpenNodes.Remove(CurrentNode);
		ClosedNodes.Add(CurrentNode);
		TArray<FPathNode*>UnclosedNeigboorNodes = FindUnclosedNeigboorNodes(CurrentNode->NeighboorNodes, ClosedNodes);
		for (auto NeighboorNode : UnclosedNeigboorNodes )
		{
			float TempG = CurrentNode->G + StraightDistance(CurrentNode, NeighboorNode);
			int32 Index;
			if (!OpenNodes.Find(NeighboorNode, Index) || TempG < NeighboorNode->G)
			{
				PathMap.Add(NeighboorNode, CurrentNode);
				NeighboorNode->G = TempG;
				NeighboorNode->F = NeighboorNode->G + StraightDistance(NeighboorNode, EndNode);
				if (!OpenNodes.Find(NeighboorNode, Index))
				{
					OpenNodes.Add(NeighboorNode);
				}
			}
		}
	}
	return false;
}

//distance beetween nodes
float ACustomNavigationData::StraightDistance(FPathNode * From, FPathNode * To)
{
	return (To->RepresentingActor->GetActorLocation() - From->RepresentingActor->GetActorLocation()).Size();
}

FPathNode * ACustomNavigationData::FindNodeWithMinF(const TArray<FPathNode*>& PathPointsToSearchIn)
{
	FPathNode* MinFPathNode = PathPointsToSearchIn[0];
	for (int32 i = 1; i < PathPointsToSearchIn.Num(); i++)
	{
		if (PathPointsToSearchIn[i]->F < MinFPathNode->F)
		{
			MinFPathNode = PathPointsToSearchIn[i];
		}
	}
	return MinFPathNode;
}

TArray<FPathNode*> ACustomNavigationData::FindUnclosedNeigboorNodes(const TArray<FPathNode*>& NeighboorNodes, const TArray<FPathNode*>& ClosedNodes)
{
	TArray<FPathNode*>UnclosedNeihboors;
	int32 Index;
	for (auto Neighboor : NeighboorNodes)
	{
		if (!ClosedNodes.Find(Neighboor, Index))
		{
			UnclosedNeihboors.Add(Neighboor);
		}
	}
	return UnclosedNeihboors;
}
