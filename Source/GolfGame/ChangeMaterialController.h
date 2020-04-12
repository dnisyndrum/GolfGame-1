// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <string>
#include "Platform_Moving.h"
#include "Ball.h"
#include "Engine/SpotLight.h"
#include "ChangeMaterialController.generated.h"


UCLASS()
class GOLFGAME_API AChangeMaterialController : public AActor
{
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties
	AChangeMaterialController();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
		class UMaterial* OnMaterial;

	UPROPERTY(EditAnywhere)
		class UMaterial* OffMaterial;

	UPROPERTY()
		class UBoxComponent* MyBoxComponent;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(EditAnywhere)
		class APlatform_Moving* AssociatedPlatform;

	UPROPERTY(EditAnywhere)
		class ABall* Ball;

	UPROPERTY(EditAnywhere)
		class USpotLightComponent* AssociatedSpotlight;

	
private:

	void TogglePlatformMovement();

	void ToggleSpotlight();

	enum SwitchState { On, Off };
	SwitchState CurrentSwitchState = Off;
	SwitchState CurrentSpotlightState = Off;
	const float SpotlightOffIntensity = 0;
	const float SpotlightOnIntensity = 1000;
	
};
