// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTGAME_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float range = 100.f;

	bool is_grabbed = false;

	UPhysicsHandleComponent* physics_handler = nullptr;
	UInputComponent* input_handler = nullptr;

	FHitResult hit;

	AActor* grabbed_actor = nullptr;

	void Grab();
	
};
