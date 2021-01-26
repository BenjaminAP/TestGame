// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorComponent.h"

// Sets default values for this component's properties
UDoorComponent::UDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FRotator currentRotation = GetOwner()->GetActorRotation();
	currentRotation.Yaw = -90.f;
	GetOwner()->SetActorRotation(currentRotation);

	InitYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitYaw;
	TargetYaw = InitYaw + 90.f;
}


// Called every frame
void UDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, 0.02f);
	FRotator DoorOpen = GetOwner()->GetActorRotation();
	DoorOpen.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorOpen);
}

