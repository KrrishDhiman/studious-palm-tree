// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"
#include "Components/CapsuleComponent.h"
#include <cstdlib>


// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = Capsule;

	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("The Floor"));
	Cube->SetupAttachment(RootComponent);

	StartingPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Starting Point"));
	StartingPoint->SetupAttachment(Cube);



}


// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();

	for(int x = 0; x <= NO_OF_RED_CUBES; x++)
	{
	SpawnObject1(FVector(rand()%17500, rand()%(Y_MAX-Y_MIN+1)+Y_MIN, 50), FRotator(1,1,1));
	}
	UE_LOG(LogTemp, Warning, TEXT("1-17500 DONE RED"));

	
	for(int x = 0; x <= NO_OF_RED_CUBES; x++)
	{
	SpawnObject2(FVector(rand()%17500, rand()%(Y_MAX-Y_MIN+1)+Y_MIN, 50), FRotator(1,1,1));
	}
	UE_LOG(LogTemp, Warning, TEXT("1-17500 DONE BLUE"));


	GetWorld()->GetTimerManager().SetTimer(EveryTenSec1, this, &AFloor::UpdateNoOfBridges, time, true);
	GetWorld()->GetTimerManager().SetTimer(EveryTenSec2, this, &AFloor::ActuallySpawningObject1, time, true);
	GetWorld()->GetTimerManager().SetTimer(EveryTenSec3, this, &AFloor::ActuallySpawningObject2, time, true);


}

void AFloor::SpawnObject1(FVector Loc, FRotator Rot) 
{

	FActorSpawnParameters SpawnParams;
	SpawnnedActorRef1 = GetWorld()->SpawnActor<AActor>(ActorToSpawn1, Loc, Rot, SpawnParams);
}

void AFloor::SpawnObject2(FVector Loc, FRotator Rot) 
{
	FActorSpawnParameters SpawnParams;
	SpawnnedActorRef2 = GetWorld()->SpawnActor<AActor>(ActorToSpawn2, Loc, Rot, SpawnParams);
}


void AFloor::ActuallySpawningObject1() 
{
	if(NO_OF_BRIDGES>1)
	{
		for(int x = 0; x <= NO_OF_RED_CUBES; x++)
		{
		/*	FVector LOCATION:
			LOCATION.X = rand()%(NO_OF_BRIDGES*17500 - 17500*(NO_OF_BRIDGES-1) + 1) + 17500*(NO_OF_BRIDGES - 1);
			LOCATION.Y = rand()%(Y_MAX-Y_MIN+1)+Y_MIN;
			LOCATION.Z = 50;*/
			SpawnObject1(FVector(rand()%(NO_OF_BRIDGES*17500 - 17500*(NO_OF_BRIDGES-1) + 1) + 17500*(NO_OF_BRIDGES - 1), rand()%(Y_MAX-Y_MIN+1)+Y_MIN, 50), FRotator(0,0,0));			
		}
		UE_LOG(LogTemp, Warning, TEXT("%i-%i DONE RED"), 17500*(NO_OF_BRIDGES-1), 17500*(NO_OF_BRIDGES));
	}
}

void AFloor::ActuallySpawningObject2() 
{
	if(NO_OF_BRIDGES>1)
	{
		for(int x = 0; x <= NO_OF_RED_CUBES; x++)
		{
		/*	FVector LOCATION:
			LOCATION.X = rand()%(NO_OF_BRIDGES*17500 - 17500*(NO_OF_BRIDGES-1) + 1) + 17500*(NO_OF_BRIDGES - 1);
			LOCATION.Y = rand()%(Y_MAX-Y_MIN+1)+Y_MIN;
			LOCATION.Z = 50;*/
			SpawnObject2(FVector(rand()%(NO_OF_BRIDGES*17500 - 17500*(NO_OF_BRIDGES-1) + 1) + 17500*(NO_OF_BRIDGES - 1), rand()%(Y_MAX-Y_MIN+1)+Y_MIN, 50), FRotator(0,0,0));
			
		}
		UE_LOG(LogTemp, Warning, TEXT("%i-%i DONE BLUE"), 17500*(NO_OF_BRIDGES-1), 17500*(NO_OF_BRIDGES));
	}
}

void AFloor::UpdateNoOfBridges() 
{
	NO_OF_BRIDGES++;
	UE_LOG(LogTemp, Warning, TEXT("No of bridges = %i"), NO_OF_BRIDGES);
}

void AFloor::Tick(float DeltaTime) 
{
	
}