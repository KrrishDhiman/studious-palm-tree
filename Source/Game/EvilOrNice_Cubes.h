// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EvilOrNice_Cubes.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class GAME_API AEvilOrNice_Cubes : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* Box;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Square;

	
public:	
	// Sets default values for this actor's properties
	AEvilOrNice_Cubes();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
