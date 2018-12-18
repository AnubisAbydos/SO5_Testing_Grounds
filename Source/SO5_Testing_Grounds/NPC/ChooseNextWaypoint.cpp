// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	// Get Blackboard Component
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	// Get Patrol Route
	auto PatrolRoute = Cast<UPatrolRoute>(OwnerComp.GetAIOwner()->GetPawn()->GetComponentByClass(UPatrolRoute::StaticClass()));
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	// Get Patrol Points and warn of empty patrol points
	TArray<AActor*> PatrolPointArray = PatrolRoute->GetPatrolPoints();
	if (PatrolPointArray.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}

	// Get current Index
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	// Set Next Waypoint
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPointArray[Index]);

	// Increment Next Index
	Index = (Index + 1) % PatrolPointArray.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	// Return Complete
	return EBTNodeResult::Succeeded;
}
