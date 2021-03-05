



#include "PlayerFriends.h"

APlayerFriends::APlayerFriends() 
{
    PrimaryActorTick.bCanEverTick = true;
}

void APlayerFriends::BeginPlay() 
{
/* 	Player = Cast<APlayerPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
    GetWorld()->GetTimerManager().SetTimer(EverySec, this, &APlayerFriends::CheckFireCondition, FireRate, true);*/
}


void APlayerFriends::Tick(float DeltaTime) 
{
    
}
/*

void APlayerFriends::MoveToBlueCube() 
{
    
}

void APlayerFriends::CalculateBlueCubeFVECTOR(float Value) 
{

	
}


*/