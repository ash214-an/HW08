#include "MovingActor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"


AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
		RootComponent = MeshComponent;

}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	float DistanceMoved = (CurrentLocation - StartLocation).Size();

	if (DistanceMoved >= MaxRange)
	{
		bMovingForward = !bMovingForward;
	}

	float Direction = bMovingForward ? 1.0f : -1.0f;
	FVector Offset = FVector(0, MoveSpeed * DeltaTime * Direction, 0);

	SetActorLocation(CurrentLocation + Offset);

	if (GEngine)
	{
		FString Dir = bMovingForward ? TEXT("->") : TEXT("<-");
		GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Cyan,
			FString::Printf(TEXT("Moving %s | DistanceMoved: %.2f"), *Dir, DistanceMoved));
	}
}

