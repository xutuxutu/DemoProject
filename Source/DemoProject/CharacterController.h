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
	class ASparkyObjectPool* SparkyObjectPool;
	FTimerHandle TimerHandle;
	bool IsFire;
protected:
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	//Binding Function
	void ForwardKeyDown(float forward);
	void RightKeyDown(float right);
	void LeftMouseButtonDown();
	void LeftMouseButtonUp();

	//Movement
	void CharacterMovement();
	void CharacterRotation();

	//Action
	void NormalAttack();
	void NormalAttackRoutine();
};
