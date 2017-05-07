// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "SparkyObjectPool.h"
#include "03_Effect/NormalAttackEffect.h"

// Sets default values
ASparkyObjectPool::ASparkyObjectPool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASparkyObjectPool::BeginPlay()
{
	Super::BeginPlay();
}

void ASparkyObjectPool::InitNormalAttackEffect()
{
	NormalAttackEffect = new FNormalAttackEffect;
	NormalAttackEffect->Lenth = 50;
	for (int i = 0; i < NormalAttackEffect->Lenth; ++i)
	{
		NormalAttackEffect->NormalAttackEffect[i] = GWorld->SpawnActor<ANormalAttackEffect>(FVector(0, 0, 0), FRotator(0, 0, 0));
		NormalAttackEffect->NormalAttackEffect[i]->SetDeActivate();
	}
}
void ASparkyObjectPool::CreateNormalAttackEffect(FVector spawnLoc, FRotator rotation)
{
	for (int i = 0; i < NormalAttackEffect->Lenth; ++i)
	{
		if (!NormalAttackEffect->NormalAttackEffect[i]->GetIsActive())
		{
			NormalAttackEffect->NormalAttackEffect[i]->SetActorLocation(spawnLoc);
			NormalAttackEffect->NormalAttackEffect[i]->SetActorRotation(rotation);
			NormalAttackEffect->NormalAttackEffect[i]->SetActivate();
			break;
		}
	}
}

// Called every frame
void ASparkyObjectPool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

