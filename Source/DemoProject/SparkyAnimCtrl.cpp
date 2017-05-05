// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "SparkyAnimCtrl.h"


USparkyAnimCtrl::USparkyAnimCtrl()
{
	ConstructorHelpers::FObjectFinder<UAnimMontage> normalAtkMontage(TEXT("AnimMontage'/Game/03_BluePrint/Sparky_NormalAttack_Montage.Sparky_NormalAttack_Montage'"));
	NormalAttackMontage = normalAtkMontage.Object;
}

void USparkyAnimCtrl::Init()
{
	//ConstructorHelpers::FObjectFinder<UAnimMontage> normalAtkMontage(TEXT("AnimMontage'/Game/03_BluePrint/Sparky_NormalAttack_Montage.Sparky_NormalAttack_Montage'"));
}

void USparkyAnimCtrl::SetMoveProperty(float forward, float right)
{
	Forward = forward;
	Right = right;
}

void USparkyAnimCtrl::SetFireButtonDown(bool fireButtonDown)
{
	FireButtonDown = fireButtonDown;
	if (FireButtonDown)
	{
		Montage_Play(NormalAttackMontage, 1.0f, EMontagePlayReturnType::MontageLength, 0.0f);
		SparkyStatus = SPARKY_STATUS::BATTLE;
	}
	else
	{
		if (Montage_IsPlaying(NormalAttackMontage))
		{
			Montage_JumpToSection(TEXT("Attack_LoopEnd"), NormalAttackMontage);
			SparkyStatus = SPARKY_STATUS::PEACE;
		}
	}
}

void USparkyAnimCtrl::SetIsFire(bool isFire)
{
	IsFire = isFire;

}