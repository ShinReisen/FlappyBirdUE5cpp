// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BirdPipe.generated.h"

UCLASS()
class FLAPPYBIRD_API ABirdPipe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABirdPipe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UBoxComponent* BoxComp;
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UStaticMeshComponent* PipeHead;
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UStaticMeshComponent* PipeBody;
	UPROPERTY(VisibleAnywhere) class UPaperSpriteComponent* PipeSprite;

	float MoveSpeed = -100.f;
};
