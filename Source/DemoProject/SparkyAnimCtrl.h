// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "SparkyStatus.h"
#include "SparkyAnimCtrl.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API USparkyAnimCtrl : public UAnimInstance
{
	GENERATED_BODY()

private :
	UAnimMontage* NormalAttackMontage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "AnimProperty", meta = (AllowPrivateAccess = "true"))
	SPARKY_STATUS SparkyStatus;
	//Anim Property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "AnimProperty", meta = (AllowPrivateAccess = "true"))
	float Forward;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "AnimProperty", meta = (AllowPrivateAccess = "true"))
	float Right;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "AnimProperty", meta = (AllowPrivateAccess = "true"))
	bool FireButtonDown;
	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Category = "AnimProperty", meta = (AllowPrivateAccess = "true"))
	bool IsFire;

public :
	USparkyAnimCtrl();

	void Init();
	void SetMoveProperty(float forward, float right);
	void SetFireButtonDown(bool fireButtonDown);
	void SetIsFire(bool isFire);
	
	bool GetIsFireButtonDown() { return FireButtonDown; }
	bool GetIsFire() { return IsFire; }
};