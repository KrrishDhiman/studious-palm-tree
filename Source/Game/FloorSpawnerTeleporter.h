// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FloorSpawnerTeleporter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UFloorSpawnerTeleporter : public UActorComponent
{
	GENERATED_BODY()

private: 
	
	FTimerHandle EverySevenPointFiveSecs;
	FVector OriginalLocation;
	FVector NewLocation;
	float TIME = 10.0f;

public:	
	// Sets default values for this component's properties
	UFloorSpawnerTeleporter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void Teleport();

};
