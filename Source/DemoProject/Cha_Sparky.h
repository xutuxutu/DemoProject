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

	FVector* moveVector;
public:
	// Sets default values for this character's properties
	ACha_Sparky();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
