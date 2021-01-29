// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine/Classes/Engine/World.h"
#include "Engine/Classes/GameFramework/PlayerController.h"

#include "DoorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTGAME_API UDoorComponent : public UActorComponent
{
	GENERATED_BODY()

	public:	
		// Sets default values for this component's properties
		UDoorComponent();

	protected:
		// Called when the game starts
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		void OpenDoor(float DeltaTime);
		void CloseDoor(float DeltaTime);

	private:
		float InitYaw;
		float CurrentYaw;

		UPROPERTY(EditAnywhere)
		float TargetOpenYaw = 90.f;

		UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

		UPROPERTY(EditAnywhere)
		AActor* ActorThatOpen;
};
