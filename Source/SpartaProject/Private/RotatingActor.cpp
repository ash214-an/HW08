#include "RotatingActor.h"
#include "Components/StaticMeshComponent.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	RotationSpeed = FRotator(0.f, 90.f, 0.f);
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationSpeed * DeltaTime);

}

