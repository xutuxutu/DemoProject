// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
private :
	class ASparkyObjectPool* SparkyObjectPool;
private:
	UMainGameInstance();
};
