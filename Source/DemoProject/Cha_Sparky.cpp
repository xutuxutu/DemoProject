// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "Cha_Sparky.h"


// Sets default values
ACha_Sparky::ACha_Sparky()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//�޽� �� ĸ�� ���� ����
	ConstructorHelpers::FObjectFinder<USkeletalMesh> model(TEXT("SkeletalMesh'/Game/02_Asset/01_Character/01_Model/Cha_Spaky.Cha_Spaky'"));
	GetMesh()->SetSkeletalMesh(model.Object);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -70.0f), FRotator(0.0f, -90.0f, 0.0f));
	GetCapsuleComponent()->SetCapsuleHalfHeight(70.0f);
	GetCapsuleComponent()->SetCapsuleRadius(22.0f);

	//ī�޶�� �������� ������Ʈ ���� �� ����
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CharacterCamera"));
	springArm->SetupAttachment(this->GetRootComponent());
	camera->SetupAttachment(springArm);
	
	springArm->TargetArmLength = 500.0f;
	springArm->SetRelativeRotation(FRotator(-57.0f, 0.0f, 0.0f));
	springArm->bInheritPitch = false;
	springArm->bInheritRoll = false;
	springArm->bInheritYaw = false;
	springArm->bDoCollisionTest = false;

	camera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ACha_Sparky::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACha_Sparky::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
