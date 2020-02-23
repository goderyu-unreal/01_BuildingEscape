// Fill out your copyright notice in the Description page of Project Settings.


#include "PositionReport.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Position report reporting for duty for Chair!"));
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();
	auto Owner = GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("Pointer Owner is nullptr"));
		return;
	}
	auto OwnerName = Owner->GetName();
	auto OwnerPosition = 
		Owner->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, 
		TEXT("Owner is %s and position is %s"), *OwnerName, *OwnerPosition);
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

