// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	capsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule collider"));
	RootComponent = capsuleComponent;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base mesh"));
	baseMesh->SetupAttachment(capsuleComponent);

	gunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun mesh"));
	gunMesh->SetupAttachment(baseMesh);

	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile spawn point"));
	projectileSpawnPoint->SetupAttachment(gunMesh);
}

void ABasePawn::RotateTurret(FVector lookAt)
{
	FVector toTarget = lookAt - gunMesh->GetComponentLocation();
	FRotator lookAtRotation = FRotator(0.0f, toTarget.Rotation().Yaw, 0.0f);

	gunMesh->SetWorldRotation(FMath::RInterpTo(gunMesh->GetComponentRotation(), lookAtRotation, UGameplayStatics::GetWorldDeltaSeconds(this), 25.0f));
}

void ABasePawn::Fire()
{
	FVector location = projectileSpawnPoint->GetComponentLocation();
	FRotator rotation = projectileSpawnPoint->GetComponentRotation();

	GetWorld()->SpawnActor<AProjectile>(projectileClass, location, rotation);
}

