// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(MyVector);
	InitialPosition = GetActorLocation();
	InitialRotation = GetActorRotation();

	SetActorLocation(InitialPosition + OffsetPosition);
	
	UE_LOG(LogTemp, Display, TEXT("Construct an Moving Platform"));
	
}

void AMovingPlatform::MovingPlatform(float DeltaTime)
{
	
	MovePlatform(PlatformVelocity*DeltaTime);
	if (ShouldPlatformReturn())
	{
		//FString name = GetName();
		//UE_LOG(LogTemp, Display, TEXT("The Actor %s is overshoot by %f"),*name,FVector::Dist(InitialPosition,CurrentLocation) - MaxDistance);
		PlatformVelocity=-PlatformVelocity;
		InitialPosition = GetActorLocation();
	}
}

void AMovingPlatform::MovePlatform(FVector vector)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation+=vector;
	SetActorLocation(CurrentLocation);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved()>MaxDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(InitialPosition,GetActorLocation());
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation+=RotationVelocity*DeltaTime;
	SetActorRotation(CurrentRotation);

	if(ReturnRotation && CurrentRotation.Equals(InitialRotation,1.0))
	{
		UE_LOG(LogTemp, Display, TEXT(">>>>>The rotation of the object %s is near zero"),*GetName());
		RotationVelocity = RotationVelocity*-1;
	}
		
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovingPlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

