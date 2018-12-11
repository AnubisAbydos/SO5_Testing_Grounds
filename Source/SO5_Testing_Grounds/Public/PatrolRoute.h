// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


/**
 * A component to store patrol points to help AI patrol behaviour
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SO5_TESTING_GROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; }

protected:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPoints;

};
