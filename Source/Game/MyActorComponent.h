// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	FTimerHandle EveryTenSec1;
	FTimerHandle EveryTenSec2;
	

	UPROPERTY(VisibleAnywhere, Category = "Variables")
	float time = 10.f;


	UPROPERTY(EditAnywhere, Category = "Variables")
	int NO_OF_BRIDGES = 1;
	

	UPROPERTY(EditAnywhere, Category = "Variables")
	int X_lenght = 8741;
	UPROPERTY(EditAnywhere, Category = "Variables")
	int Y_Max = 303;
	UPROPERTY(EditAnywhere, Category = "Variables")
	int Y_Min = -303;
	UPROPERTY(EditAnywhere, Category = "Variables")
	int Z_Const = 50;


public:	
	// Sets default values for this component's properties
	UMyActorComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	
	
	
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn1;



	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn2;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UFUNCTION()
	void SpawnObject1(FVector Loc, FRotator Rot);


	UFUNCTION()
	void SpawnObject2(FVector Loc, FRotator Rot);


	UFUNCTION()
	void ActuallySpawningObject1();


	UFUNCTION()
	void ActuallySpawningObject2();



};