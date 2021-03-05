// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

class UCapsuleComponent;


UCLASS()
class GAME_API AFloor : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCapsuleComponent* Capsule;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Cube;
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* StartingPoint;
	

public:	
	// Sets default values for this actor's properties
	AFloor();


	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn1;
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	AActor* SpawnnedActorRef1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")	
	AActor* SpawnnedActorRef2;


/*	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector LocationRed[] = {};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FVector LocationBlue[] = {};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int x = 0;*/



private:


	FTimerHandle EveryTenSec1;
	FTimerHandle EveryTenSec2;
	FTimerHandle EveryTenSec3;
	UPROPERTY(EditAnywhere, Category = "Time")
	float time = 10.f;


	UPROPERTY(EditAnywhere, Category = "Variables")
	int X_MIN = -8750; 
	UPROPERTY(EditAnywhere, Category = "Variables")	
	int X_MAX = 8750; 
	UPROPERTY(EditAnywhere, Category = "Variables")
	int Y_MIN = -303; 
	UPROPERTY(EditAnywhere, Category = "Variables")
	int Y_MAX = 303; 
	UPROPERTY(EditAnywhere, Category = "Variables")
	int Z_CONST = 50; 

	UPROPERTY(EditAnywhere, Category = "Variables")
	int NO_OF_RED_CUBES = 3;
	UPROPERTY(EditAnywhere, Category = "Variables")	
	int NO_OF_BLUE_CUBES = 3;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void SpawnObject1(FVector Loc, FRotator Rot);
	UFUNCTION()
	void SpawnObject2(FVector Loc, FRotator Rot);
	UFUNCTION()
	void ActuallySpawningObject1();
	UFUNCTION()
	void ActuallySpawningObject2();
	UFUNCTION()
	void UpdateNoOfBridges();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int NO_OF_BRIDGES = 1;

};
