// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "NormalAttackEffect.h"


// Sets default values
ANormalAttackEffect::ANormalAttackEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bullet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet"));
	SetRootComponent(bullet);

	ConstructorHelpers::FObjectFinder<UStaticMesh> bulletMesh(TEXT("StaticMesh'/Game/02_Asset/03_Effect/01_Character/01_Attack/NormalAttackBullet/NormalAttackBullet_Mesh.NormalAttackBullet_Mesh'"));
	bullet->SetStaticMesh(bulletMesh.Object);
	bullet->SetMobility(EComponentMobility::Movable);
	//bullet->SetRelativeRotation(FRotator(-90, 0, 0));
}

// Called when the game starts or when spawned
void ANormalAttackEffect::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANormalAttackEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANormalAttackEffect::SetActivate()
{
	IsActive = true;
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);
}

void ANormalAttackEffect::SetDeActivate()
{
	IsActive = false;
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}


