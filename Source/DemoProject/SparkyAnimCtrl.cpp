// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "SparkyAnimCtrl.h"

void USparkyAnimCtrl::SetMoveProperty(float forward, float right)
{
	Forward = forward;
	Right = right;
	UE_LOG(LogClass, Warning, TEXT("%f %f"), forward, right);
}

void USparkyAnimCtrl::SetFireButtonDown(bool fireButtonDown)
{
	FireButtonDown = fireButtonDown;
}
void USparkyAnimCtrl::SetIsFire(bool isFire)
{
	IsFire = isFire;
}