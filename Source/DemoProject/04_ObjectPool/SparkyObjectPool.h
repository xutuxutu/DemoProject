// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SparkyObjectPool.generated.h"


typedef struct _FNormalAttackEffect
{
	class ANormalAttackEffect* NormalAttackEffect[50];
	int Lenth;
}FNormalAttackEffect;

UCLASS()
class DEMOPROJECT_API ASparkyObjectPool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASparkyObjectPool();
	FNormalAttackEffect* NormalAttackEffect;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void InitNormalAttackEffect();
	void CreateNormalAttackEffect(FVector spawnLoc, FRotator rotation);
	virtual void Tick(float DeltaTime) override;
};
