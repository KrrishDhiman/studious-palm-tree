// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorSpawnerTeleporter.h"

// Sets default values for this component's properties
UFloorSpawnerTeleporter::UFloorSpawnerTeleporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFloorSpawnerTeleporter::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(EverySevenPointFiveSecs, this, &UFloorSpawnerTeleporter::Teleport, TIME, true);
	
}

void UFloorSpawnerTeleporter::Teleport() 
{
	OriginalLocation = GetOwner()->GetActorLocation();
	NewLocation.X = OriginalLocation.X + 17500.f;
	NewLocation.Y = OriginalLocation.Y; NewLocation.Z = OriginalLocation.Z;
	GetOwner()->SetActorLocation(NewLocation);
	UE_LOG(LogTemp, Warning, TEXT("Teleported!"));
}


/*
8750















*/