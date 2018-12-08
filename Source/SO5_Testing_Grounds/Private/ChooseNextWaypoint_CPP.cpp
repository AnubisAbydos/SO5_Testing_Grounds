// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/ChooseNextWaypoint_CPP.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "../Public/PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWaypoint_CPP::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	// Get Blackboard Component
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	// Gets AI Controller->Pawn and casts to PatrollingGuard then calls GetPatrolPoints()
	TArray<AActor*> PatrolPointArray = (Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn()))->GetPatrolPoints();

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
