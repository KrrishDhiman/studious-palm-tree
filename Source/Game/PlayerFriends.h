// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerFriends.generated.h"



UCLASS()
class GAME_API APlayerFriends : public AActor
{
	GENERATED_BODY()

/*private:
	UPROPERTY(EditAnywhere, Category = "Variable s")
	float Speed = 5.0f;
	UPROPERTY(EditAnywhere)
	FTimerHandle EverySec;
	UPROPERTY(EditAnywhere, Category = "Variable s")
	float OneByTime = 100.0;
	FVector MoveDirection;
	FQuat RotationDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable s", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable s", meta = (AllowPrivateAccess = "true"))
	float RotateSpeed = 150.0f;*/

protected:
	UFUNCTION()
	virtual void BeginPlay() override;
/*	UFUNCTION()
	void MoveToBlueCube();
	UFUNCTION()
	void CalculateBlueCubeFVECTOR(float Value);*/

public:
	APlayerFriends();
	UFUNCTION()
	virtual void Tick(float DeltaTime) override;
	/*UPROPERTY(EditAnywhere, Category = "Classes")
	TSubclassOf<AActor> BlueCuubee;

	UPROPERTY(EditAnywhere, Category = "")
	AActor* BlueCubeRef;*/

};
