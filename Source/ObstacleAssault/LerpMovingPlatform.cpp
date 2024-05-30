// Fill out your copyright notice in the Description page of Project Settings.

#include "LerpMovingPlatform.h"

// Sets default values
ALerpMovingPlatform::ALerpMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALerpMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void ALerpMovingPlatform::Tick(float DeltaTime)
{
	if (ElapsedTime > Delay)
	{
		FVector position = LinearInterpolate(StartLocation, EndLocation, ElapsedTime - Delay, Duration);
		SetActorLocation(position);
	}
	ElapsedTime += DeltaTime;
	Super::Tick(DeltaTime);
}

FVector ALerpMovingPlatform::LinearInterpolate(FVector A, FVector B, float InElapsedTime, float InDuration)
{
	// One cycle is there and back
	float CycleTime = InDuration * 2;

	// Elapsed Time restarts for each cycle
	float t = FMath::Fmod(InElapsedTime, CycleTime);

	// Calculates the time stamp for forwards and backwards movement
	if (t < Duration)
	{
		t = t / InDuration;
	}
	else
	{
		t = (CycleTime - t) / InDuration;
	}

	// Calculate the interpolated vector
	return A + (B - A) * t;
}
