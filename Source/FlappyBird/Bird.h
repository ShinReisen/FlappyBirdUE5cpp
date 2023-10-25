// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h"


UCLASS()
class FLAPPYBIRD_API ABird : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABird();
	UFUNCTION(BlueprintImplementableEvent) void HandleReset();
	UFUNCTION(BlueprintCallable, Category = "Components") void SetBirdAnimation(class UPaperFlipbook* NewAnimation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable) int GetScore();
protected:

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UCapsuleComponent* CapsuleComp;
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(EditDefaultsOnly, Category = "Components") class USoundBase* FlapSound;
	UPROPERTY(EditDefaultsOnly, Category = "Components") class USoundBase* SplatSound;

	UPROPERTY(VisibleAnywhere, Category = "Components") class UPaperFlipbookComponent* BirdFlipbook;

	UPROPERTY(EditAnywhere, Category = "Jump Components") float JumpStrength = 400.f;
	bool IsAlive = true;
	UPROPERTY(EditAnywhere, Category = "Jump Components") float JumpDuration = 1;

	UFUNCTION() void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION() void OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	void Jump();


	APlayerController* BirdPlaterController;
	int Score = 0;

};
