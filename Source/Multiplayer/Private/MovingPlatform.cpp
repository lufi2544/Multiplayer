// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Engine/World.h"

AMovingPlatform::AMovingPlatform() 
	{

	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);

	}



void AMovingPlatform::BeginPlay() 
	{

	Super::BeginPlay();

	if(HasAuthority())
		{

		// Replication Set Up
		SetReplicates(true);

		//Movement Replication for the client
		SetReplicateMovement(true);
	
		}
	



	}

 void AMovingPlatform::Tick(float DeltaSeconds)
	{


	 Super::Tick(DeltaSeconds);

	 FVector Location;

	 // Asking if is the server then we execute a function Not on server means on client
	 if (HasAuthority()) 
	 {
		 MovePlatformAmountY();
	 }
	
	}
	

 bool AMovingPlatform::MovePlatformAmountY()
	{

	 bIsBack = false;
	 FVector ActorLocation = GetActorLocation();

	 ActorLocation += FVector(0, MovementSpeed, 0);

	 SetActorLocation(ActorLocation);
		
	 return false;
	 }


		
	
