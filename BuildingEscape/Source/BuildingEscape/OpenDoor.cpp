// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "Engine/TriggerVolume.h"
#include "Engine.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	OriginRotator = Owner->GetTransform().GetRotation().Rotator();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	// If the ActorThatOpens is in the volume
	// if(DoOnce)
	// {
		if(PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
		{
			OpenDoor();
			// DoOnce = !DoOnce;
			LastDoorOpenTime = GetWorld()->GetTimeSeconds();
		}

		if ((GetWorld()->GetTimeSeconds() - LastDoorOpenTime) > DoorCloseDelay)
		{
			CloseDoor();
		}
	// }
}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.f, OriginRotator.Yaw + OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, OriginRotator.Yaw, 0.f));
}