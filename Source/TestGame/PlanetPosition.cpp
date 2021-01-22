// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetPosition.h"

// Sets default values for this component's properties
UPlanetPosition::UPlanetPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlanetPosition::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FString actorName = GetOwner()->GetName();
	FString actorPosition = GetOwner()->GetActorLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *actorName);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *actorPosition);
	
}


// Called every frame
void UPlanetPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

