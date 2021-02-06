// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/Classes/Engine/World.h"
#include "Engine/Classes/GameFramework/PlayerController.h"

#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...

	UE_LOG(LogTemp, Warning, TEXT("Grabber ready"));

	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	FVector player_viewpoint_location;
	FRotator player_viewpoint_rotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT player_viewpoint_location, OUT player_viewpoint_rotation);
	UE_LOG(LogTemp, Warning, TEXT("Location: %s | Rotation: %s"), *player_viewpoint_location.ToString(), *player_viewpoint_rotation.ToString());
}

