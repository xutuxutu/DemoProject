// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "NormalAttackEffect.generated.h"

UCLASS()
class DEMOPROJECT_API ANormalAttackEffect : public AActor
{
	GENERATED_BODY()
private :
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* bullet;
	bool IsActive;
public:	
	// Sets default values for this actor's properties
	ANormalAttackEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetIsActive() { return IsActive; }

	void SetActivate();
	void SetDeActivate();
};
