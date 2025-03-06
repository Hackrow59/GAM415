// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAM415_GonzalezPickUpComponent.h"

UGAM415_GonzalezPickUpComponent::UGAM415_GonzalezPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UGAM415_GonzalezPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UGAM415_GonzalezPickUpComponent::OnSphereBeginOverlap);
}

void UGAM415_GonzalezPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AGAM415_GonzalezCharacter* Character = Cast<AGAM415_GonzalezCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
