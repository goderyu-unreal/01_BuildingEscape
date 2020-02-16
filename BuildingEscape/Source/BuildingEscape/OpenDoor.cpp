// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "Engine/TriggerVolume.h"
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
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	// If the ActorThatOpens is in the volume
	if(DoOnce)
	{
		if(PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
		{
			OpenDoor();
			DoOnce = !DoOnce;
		}
	}
}

void UOpenDoor::OpenDoor()
{
	//Find Owning object
	auto Owner = GetOwner();

	//Find origin rotator
	auto OriginRotator = Owner->GetActorRotation();
	//Create a rotator
	auto NewRotator = FRotator(0.f, OpenAngle, 0.f);
	//Set the door rotation
	Owner->SetActorRotation(OriginRotator + NewRotator);
}