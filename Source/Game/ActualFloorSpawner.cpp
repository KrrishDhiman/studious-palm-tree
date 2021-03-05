// Fill out your copyright notice in the Description page of Project Settings.


#include "ActualFloorSpawner.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AActualFloorSpawner::AActualFloorSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AActualFloorSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(OutHandle, this, &AActualFloorSpawner::SpawnBridge, TimeToSpawn, true);

    //GetWorld()->GetTimerManager().SetTimer(InHandle, this, &AActualFloorSpawner::Teleport, TimeToTeleport, true);

}

void AActualFloorSpawner::SpawnBridge() 
{
    if(UsefulActorBP)  //If the usefulactorbp is valid
    {
        FActorSpawnParameters SpawnParams;
 
        AFloor* ActorRef = GetWorld()->SpawnActor<AFloor>(UsefulActorBP, GetTransform(), SpawnParams);
    //UE_LOG(LogTemp, Warning, TEXT("Msg from Walker#72858, Spawnned The Bridge Succesfully!, LOCATION = %f"), ActorRef->GetActorLocation().X);
    }
}

/*
void AActualFloorSpawner::Teleport() 
{
    OriginalLocation = GetOwner()->GetActorLocation();
    NewLocation.X = OriginalLocation.X + 17495.f;
    NewLocation.Y = OriginalLocation.Y;
    NewLocation.Z = OriginalLocation.Z;
    GetOwner()->SetActorLocation(NewLocation);
    UE_LOG(LogTemp, Warning, TEXT("Msg from Walker#72858, Teleported The Bridge Spawnner Succesfully!"));
}
*/


// Called every frame
void AActualFloorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    

}

