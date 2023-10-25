// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "Components/BoxComponent.h"
#include "BirdPipe.h"
#include "Cone.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	RootComponent = BoxComp;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UFUNCTION(BlueprintCallable) void ASpawner::SpawnPipes()
{

	//UE_LOG(LogTemp, Warning, TEXT("spawning pipes"));
	FRotator RotationDifference = FRotator(0.f, 0.f, 180.f);
	FVector PipeLenght = FVector(0.f, 0.f, 330.f);
	FVector PipeGap = FVector(0.f, 0.f, 200.f);
	FVector PipeChange = FVector(0.f, 0.f, FMath::FRandRange(-200.f, 200.f));
	auto BottomPipe = GetWorld()->SpawnActor<ABirdPipe>(BirdPipe, RootComponent->GetComponentLocation() - PipeLenght - PipeGap + PipeChange, RootComponent->GetComponentRotation() + RotationDifference);
	auto TopPipe = GetWorld()->SpawnActor<ABirdPipe>(BirdPipe, RootComponent->GetComponentLocation() + PipeLenght + PipeGap + PipeChange, RootComponent->GetComponentRotation());
	auto Cone = GetWorld()->SpawnActor<ACone>(ScoreCone, RootComponent->GetComponentLocation() + PipeChange, RootComponent->GetComponentRotation());


	return UFUNCTION(BlueprintCallable) void();
}



