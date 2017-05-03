// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Cha_Sparky.generated.h"

UCLASS()
class DEMOPROJECT_API ACha_Sparky : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* springArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "AnimationProperty", meta=(AllowPrivateAccess="true"))
	float Forward;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "AnimationProperty", meta = (AllowPrivateAccess = "true"))
	float Right;

	float RunSpeed;
	float WalkSpeed;
public:
	// Sets default values for this character's properties
	ACha_Sparky();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetMoveAnim(FVector moveVector);
	
	float GetRunSpeed() { return RunSpeed; }
	float GetWalkSpeed() { return WalkSpeed; }
};
