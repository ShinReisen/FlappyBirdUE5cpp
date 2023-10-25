// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ScoreInstance.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API UScoreInstance : public UGameInstance
{
	GENERATED_BODY()
		
public:
	UPROPERTY(EditAnywhere, Category = "Game variables") int ScoreGlobal = 0;
};
