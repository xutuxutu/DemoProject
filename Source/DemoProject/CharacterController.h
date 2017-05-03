// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CharacterController.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API ACharacterController : public APlayerController
{
	GENERATED_BODY()
	
private:
	FVector MoveVector;
	class ACha_Sparky* Player;
public :
	ACharacterController();

protected:
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void ForwardKeyDown(float forward);
	void RightKeyDown(float right);
	void CharacterMovement();
	void CharacterRotation();
};
