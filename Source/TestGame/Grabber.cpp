// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
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

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT player_viewpoint_location,
		OUT player_viewpoint_rotation
	);

	FVector line_trace_end = player_viewpoint_location + player_viewpoint_rotation.Vector() * 100.f;

	// DrawDebugLine(
	// 	GetWorld(), 
	// 	player_viewpoint_location, 
	// 	line_trace_end, 
	// 	FColor(0, 255, 0), 
	// 	false, 0.f, 0, 10.f
	// );

	FHitResult hit;
	FCollisionQueryParams trace_params(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(OUT hit, player_viewpoint_location, 
		line_trace_end,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		trace_params
	);
	

	if (hit.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *hit.GetActor()->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Actor collision"));
	}
}

