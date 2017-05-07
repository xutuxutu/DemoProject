// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Engine.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class SPARKY_ANIM_STATUS : uint8
{
	PEACE 	UMETA(DisplayName = "PEACE"),
	BATTLE 	UMETA(DisplayName = "BATTLE"),
};
 