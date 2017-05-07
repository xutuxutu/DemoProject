// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "Kismet/KismetMathLibrary.h"
#include "Cha_Sparky.h"
#include "SparkyAnimCtrl.h"


// Sets default values
ACha_Sparky::ACha_Sparky()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//메쉬 및 캡슐 세부 설정
	ConstructorHelpers::FObjectFinder<USkeletalMesh> model(TEXT("SkeletalMesh'/Game/02_Asset/01_Character/01_Model/Cha_Spaky.Cha_Spaky'"));
	GetMesh()->SetSkeletalMesh(model.Object);

	ConstructorHelpers::FObjectFinder<UAnimBlueprint> animBP(TEXT("AnimBlueprint'/Game/03_BluePrint/AB_SparkyAnimCtrl.AB_SparkyAnimCtrl'"));
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

	CurMoveVec = FVector2D(0.0f, 0.0f);
	FinalMoveVec = FVector2D(0.0f, 0.0f);
	RunSpeed = 0.5f;
	WalkSpeed = 0.2f;
	NormalAttackSpeed = 0.2f;
	FirePointSocketName = FName(TEXT("FirePointSocket"));
}

// Called when the game starts or when spawned
void ACha_Sparky::BeginPlay()
{
	Super::BeginPlay();
	SparkyAnimCtrl = Cast<USparkyAnimCtrl>(GetMesh()->GetAnimInstance());
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
	FinalMoveVec = FVector2D(moveVector.X, moveVector.Y);
	
	CurMoveVec.X = UKismetMathLibrary::Lerp(CurMoveVec.X, FinalMoveVec.X, FApp::GetDeltaTime() * 5.0f);
	CurMoveVec.Y = UKismetMathLibrary::Lerp(CurMoveVec.Y, FinalMoveVec.Y, FApp::GetDeltaTime() * 5.0f);

	SparkyAnimCtrl->SetMoveProperty(CurMoveVec.X, CurMoveVec.Y);
}

void ACha_Sparky::SetFireButtonDown(bool isDown)
{
	SparkyAnimCtrl->SetFireButtonDown(isDown);
}

float ACha_Sparky::GetMoveSpeed()
{
	return SparkyAnimCtrl->GetAnimStatus() == SPARKY_ANIM_STATUS::PEACE ? RunSpeed : WalkSpeed;
}

FVector ACha_Sparky::GetFirePointSocketLocation() const
{
	return GetMesh()->GetSocketLocation(FirePointSocketName);
}