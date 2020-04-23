// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SphereComponent.h"
#include "ConstructorHelpers.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	VisualMesh->SetupAttachment(SphereVisual);*/

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual Mesh"));
	RootComponent = VisualMesh;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetupAttachment(RootComponent);

	BallMaterial = CreateDefaultSubobject<UMaterial>(TEXT("Ball Material"));
}

void ABall::AddForce()
{
	
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

