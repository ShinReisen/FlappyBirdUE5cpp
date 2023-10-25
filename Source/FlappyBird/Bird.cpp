// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	BirdFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("BirdFlipbook"));
	BirdFlipbook->SetupAttachment(RootComponent);

	FlapSound = CreateDefaultSubobject<USoundBase>(TEXT("Flap Sound"));
	SplatSound = CreateDefaultSubobject<USoundBase>(TEXT("Splat Sound"));
}

void ABird::SetBirdAnimation(UPaperFlipbook* NewAnimation)
{
	if (BirdFlipbook)
	{
		BirdFlipbook->SetFlipbook(NewAnimation);
	}
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();

	CapsuleComp->OnComponentHit.AddDynamic(this, &ABird::OnHit);
	CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &ABird::OnOverlapStart);
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ABird::Jump);
}

int ABird::GetScore()
{
	return Score;
}

UFUNCTION() void ABird::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//CapsuleComp->SetEnableGravity(false);
	if (IsAlive) {
		SetActorTickEnabled(false);
		UGameplayStatics::PlaySound2D(GetWorld(), SplatSound, 1, 1, 0, NULL, this, true);
		HandleReset();
		this->DisableInput(BirdPlaterController);
		IsAlive = false;
		BirdFlipbook->Stop();
	}

	
	return UFUNCTION() void();
}

UFUNCTION() void ABird::OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Score++;
	OtherActor->Destroy();
	return UFUNCTION() void();
}

void ABird::Jump()
{
	FVector JumpImpulse = FVector(0.f, 0.f, JumpStrength);
	//CapsuleComp->AddImpulse(JumpImpulse, NAME_None, true);
	CapsuleComp->BodyInstance.SetLinearVelocity(JumpImpulse, false);
	UGameplayStatics::PlaySound2D(GetWorld(), FlapSound, 1, 1, 0, NULL, this, true);
}
