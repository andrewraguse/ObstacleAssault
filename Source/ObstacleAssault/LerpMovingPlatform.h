// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LerpMovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API ALerpMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALerpMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector EndLocation;
	UPROPERTY(EditAnywhere)
	float Duration;
	UPROPERTY(EditAnywhere)
	float Delay;

private:
	FVector StartLocation;
	float ElapsedTime;

	FVector LinearInterpolate(FVector A, FVector B, float InElapsedTime, float InDuration);
};
