// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.h"
#include "ActualFloorSpawner.generated.h"


class AFloor;
class APlayerPawn;

UCLASS()
class GAME_API AActualFloorSpawner : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly,Category="Actor Spawning")
	TSubclassOf<AFloor> UsefulActorBP;
	UPROPERTY(EditDefaultsOnly, Category="Actor Spawning")
	float TimeToSpawn = 7.5f;
//	float TimeToTeleport = 7.5001;
	FTimerHandle OutHandle;
//	FTimerHandle InHandle;
/*  FVector OriginalLocation;
	FVector NewLocation; */

	
public:	
	// Sets default values for this actor's properties
	AActualFloorSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void SpawnBridge();
	/*UFUNCTION()
	void Teleport();*/

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};