// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"
#include <cstdlib>

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();



	ActuallySpawningObject1();
	ActuallySpawningObject2();

	GetWorld()->GetTimerManager().SetTimer(EveryTenSec1, this, &UMyActorComponent::ActuallySpawningObject1, time, true);
	GetWorld()->GetTimerManager().SetTimer(EveryTenSec2, this, &UMyActorComponent::ActuallySpawningObject2, time, true);
	
}

void UMyActorComponent::SpawnObject1(FVector Loc, FRotator Rot) 
{
	FActorSpawnParameters SpawnParams;
	AActor* SpawnnedActorRef1 = GetWorld()->SpawnActor<AActor>(ActorToSpawn1, Loc, Rot, SpawnParams);
}

void UMyActorComponent::SpawnObject2(FVector Loc, FRotator Rot) 
{
	FActorSpawnParameters SpawnParams;
	AActor* SpawnnedActorRef2 = GetWorld()->SpawnActor<AActor>(ActorToSpawn2, Loc, Rot, SpawnParams);
}

void UMyActorComponent::ActuallySpawningObject1() 
{
	NO_OF_BRIDGES++;
	for(int x = 0; x <=6; x++)
	SpawnObject1(FVector(abs((rand() % X_lenght)*NO_OF_BRIDGES - (NO_OF_BRIDGES-1)*X_lenght), rand()%Y_Max + Y_Min, Z_Const), FRotator(1, 1, 1));
	UE_LOG(LogTemp, Warning, TEXT("Location: %i, %i"),((rand() % X_lenght)*NO_OF_BRIDGES - (NO_OF_BRIDGES-1)*X_lenght), rand()%Y_Max - Y_Min);	
}

void UMyActorComponent::ActuallySpawningObject2() 
{
	for(int x = 0; x <=6; x++)
	SpawnObject2(FVector(abs((rand() % X_lenght)*NO_OF_BRIDGES - (NO_OF_BRIDGES-1)*X_lenght), rand()%Y_Max + Y_Min, Z_Const), FRotator(1, 1, 1));
	UE_LOG(LogTemp, Warning, TEXT("Location: %i, %i"), ((rand() % X_lenght)*NO_OF_BRIDGES - (NO_OF_BRIDGES-1)*X_lenght), rand()%Y_Max - Y_Min);
}


// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

