// Fill out your copyright notice in the Description page of Project Settings.


#include "Cone.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACone::ACone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);
}

// Called when the game starts or when spawned
void ACone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RootComponent) {
		FVector DeltaLocation = FVector::ZeroVector;
		DeltaLocation.X = MoveSpeed * DeltaTime;
		RootComponent->SetWorldLocation(RootComponent->GetComponentLocation() + DeltaLocation);

		if (RootComponent->GetComponentLocation().X < -1100) Destroy();
	}
}

