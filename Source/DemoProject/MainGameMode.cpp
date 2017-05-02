// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoProject.h"
#include "MainGameMode.h"

AMainGameMode::AMainGameMode()
{
	//에디터 실행 초기화중에 생성자 실행(71 per)
	UE_LOG(LogClass, Warning, TEXT("SetMainGameMode"));
}


