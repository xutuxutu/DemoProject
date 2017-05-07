// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterController.h"
#include "Cha_Sparky.h"
#include "04_ObjectPool/SparkyObjectPool.h"


ACharacterController::ACharacterController()
{
	MoveVector = FVector(0.0f, 0.0f, 0.0f);
	IsFire = false;
}

void ACharacterController::BeginPlay()
{
	bShowMouseCursor = true;
	Player = Cast<ACha_Sparky>(GetPawn());

	SparkyObjectPool = GWorld->SpawnActor<ASparkyObjectPool>(FVector(0, 0, 0), FRotator(0,0,0));
	SparkyObjectPool->InitNormalAttackEffect();
}


void ACharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ACharacterController::ForwardKeyDown);
	InputComponent->BindAxis("MoveRight", this, &ACharacterController::RightKeyDown);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACharacterController::LeftMouseButtonDown);
	InputComponent->BindAction("Fire", IE_Released, this, &ACharacterController::LeftMouseButtonUp);
}

void ACharacterController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	//Movement
	CharacterRotation();
	CharacterMovement();
}

void ACharacterController::ForwardKeyDown(float forward) { MoveVector.X = forward; }
void ACharacterController::RightKeyDown(float right) { MoveVector.Y = right; }
void ACharacterController::LeftMouseButtonDown() 
{ 
	IsFire = true;
	Player->SetFireButtonDown(true); 
	NormalAttack();
}
void ACharacterController::LeftMouseButtonUp() 
{
	IsFire = false;
	Player->SetFireButtonDown(false); 
}

void ACharacterController::CharacterMovement()
{
	MoveVector.Normalize();
	Player->SetMoveAnim(MoveVector);
	if (MoveVector.Size() > 0.0f)
	{
		GetPawn()->AddMovementInput(MoveVector * Player->GetMoveSpeed());
	}
}

void ACharacterController::CharacterRotation()
{
	FVector2D mousePos, actorPos, charToMouse;
	FVector worldPos, worldDir;
	GetMousePosition(mousePos.X, mousePos.Y);

	ProjectWorldLocationToScreen(GetPawn()->GetActorLocation(), actorPos, false);
	DeprojectScreenPositionToWorld(actorPos.X, actorPos.Y, worldPos, worldDir);
	charToMouse = mousePos - actorPos;

	float angle = atan2(-charToMouse.Y, charToMouse.X);
	angle = UKismetMathLibrary::RadiansToDegrees(angle);

	GetPawn()->SetActorRotation(FRotator(0.0f, 90.0f - angle, 0.0f));
	//DrawDebugSphere(GetWorld(), worldPos, 1, 45, FColor(83, 255, 83, 255), false, 0.15f);
}

void ACharacterController::NormalAttack()
{
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ACharacterController::NormalAttackRoutine, Player->GetNormalAttackSpeed(), true, 0.0f);
}

void ACharacterController::NormalAttackRoutine()
{
	if (IsFire)
	{
		SparkyObjectPool->CreateNormalAttackEffect(Player->GetFirePointSocketLocation(), GetPawn()->GetActorRotation());
	}
}