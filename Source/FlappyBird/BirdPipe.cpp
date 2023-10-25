// Fill out your copyright notice in the Description page of Project Settings.


#include "BirdPipe.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABirdPipe::ABirdPipe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	RootComponent = BoxComp;

	PipeHead = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pipe head"));
	PipeHead->SetupAttachment(BoxComp);

	PipeBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pipe body"));
	PipeBody->SetupAttachment(BoxComp);

	PipeSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Pipe Sprite"));
	PipeSprite->SetupAttachment(RootComponent);  


}

// Called when the game starts or when spawned
void ABirdPipe::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABirdPipe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RootComponent) {
		FVector DeltaLocation = FVector::ZeroVector;
		DeltaLocation.X = MoveSpeed * DeltaTime;
		RootComponent->SetWorldLocation(RootComponent->GetComponentLocation() + DeltaLocation);

		if (RootComponent->GetComponentLocation().X < -1100) Destroy();
	}


}

