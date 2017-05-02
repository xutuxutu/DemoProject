// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterController.h"


ACharacterController::ACharacterController()
{
}

void ACharacterController::BeginPlay()
{
	bShowMouseCursor = true;
	//PCamera = GWorld->SpawnActor<APlayerCamera>(FVector(0, 0, 0), FRotator(0, 0, 0));
	//SetViewTarget(PCamera);
	//PCamera->AutoReceiveInput = EAutoReceiveInput::Player0;
}


void ACharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ACharacterController::ForwardKeyDown);
	InputComponent->BindAxis("MoveRight", this, &ACharacterController::RightKeyDown);
}

void ACharacterController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CharacterMovement();
	CharacterRotation();

	//PCamera->SetCameraPosition(GetPawn()->GetActorLocation());
}

void ACharacterController::ForwardKeyDown(float forward) {	MoveVector.X = forward; }
void ACharacterController::RightKeyDown(float right) { MoveVector.Y = right; }

void ACharacterController::CharacterMovement()
{
	MoveVector.Normalize();
	if (MoveVector.Size() > 0.0f)
	{
		GetPawn()->AddMovementInput(MoveVector);
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