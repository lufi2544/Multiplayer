// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()



public:

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay()override;


protected:

	UPROPERTY(EditAnywhere, Category = "Attributes")
	float MovementSpeed = 1;



	bool bHasReached = false;
	bool bIsBack = false;

	bool MovePlatformAmountY();
	



private:

	AMovingPlatform();
	
};
