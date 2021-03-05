// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"


class UCapsuleComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GAME_API APlayerPawn : public APawn
{
	GENERATED_BODY()

private: 
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Body;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* SphereSpawnPt;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* Camera;



	FVector MoveDirection;
	FQuat RotationDirection;
	FVector SideMovingDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))	
	float RotateSpeed = 100.0f;

	UFUNCTION()
	void CalculateMoveInput(float Value);
	UFUNCTION()
	void CalculateRotateInput(float Value);
	UFUNCTION()
	void Move();
	UFUNCTION()	
	void Rotate();


public:
	// Sets default values for this pawn's properties
	APlayerPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
