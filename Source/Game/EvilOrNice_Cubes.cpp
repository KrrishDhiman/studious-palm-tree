// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilOrNice_Cubes.h"
#include "Components/BoxComponent.h"

// Sets default values
AEvilOrNice_Cubes::AEvilOrNice_Cubes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
//	Box = RootComponent;



	Square = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Square->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEvilOrNice_Cubes::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEvilOrNice_Cubes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

