// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "Cha_Sparky.h"


// Sets default values
ACha_Sparky::ACha_Sparky()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//메쉬 및 캡슐 세부 설정
	ConstructorHelpers::FObjectFinder<USkeletalMesh> model(TEXT("SkeletalMesh'/Game/02_Asset/01_Character/01_Model/Cha_Spaky.Cha_Spaky'"));
	GetMesh()->SetSkeletalMesh(model.Object);

	ConstructorHelpers::FObjectFinder<UAnimBlueprint> animBP(TEXT("AnimBlueprint'/Game/03_BluePrint/AB_SparkyAnimCtrl.AB_SparkyAnimCtrl'"));
	if (!animBP.Succeeded())
		UE_LOG(LogClass, Warning, TEXT("Failed Loaded AnimBlueprint"));
	GetMesh()->SetAnimInstanceClass(animBP.Object->GetAnimBlueprintGeneratedClass());

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -70.0f), FRotator(0.0f, -90.0f, 0.0f));
	GetCapsuleComponent()->SetCapsuleHalfHeight(70.0f);
	GetCapsuleComponent()->SetCapsuleRadius(22.0f);

	//카메라와 스프링암 컴포넌트 생성 및 설정
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

	RunSpeed = 0.5f;
	WalkSpeed = 0.2f;
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

void ACha_Sparky::SetMoveAnim(FVector moveVector)
{
	moveVector = GetTransform().InverseTransformVector(moveVector);
	moveVector.Normalize();

	Forward = moveVector.X;
	Right = moveVector.Y;
	//UE_LOG(LogClass, Warning, TEXT("%f %f %f"), moveVector.X, moveVector.Y, moveVector.Z);
}
