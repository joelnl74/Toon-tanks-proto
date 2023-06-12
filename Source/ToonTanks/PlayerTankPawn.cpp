// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerTankPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include <Kismet/GameplayStatics.h>
#include "DrawDebugHelpers.h"

APlayerTankPawn::APlayerTankPawn()
{
	springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Sprint arm"));
	springArmComponent->SetupAttachment(RootComponent);
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->SetupAttachment(springArmComponent);
	trailParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Trail particle system"));
	trailParticleSystem->SetupAttachment(RootComponent);
}

void APlayerTankPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerTankPawn::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerTankPawn::Rotate);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APlayerTankPawn::Fire);
}

void APlayerTankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playerController == nullptr)
	{
		return;
	}
	FHitResult result;

	playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, result);
	DrawDebugSphere(GetWorld(), result.ImpactPoint, 25, 1, FColor::Red, false, -1.0f);
	RotateTurret(result.ImpactPoint);
}

void APlayerTankPawn::HandleOnDestroy()
{
	Super::HandleOnDestroy();

	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	m_isAlive = false;
}

void APlayerTankPawn::BeginPlay()
{
	Super::BeginPlay();

	playerController = Cast<APlayerController>(GetController());
	trailParticleSystem->DeactivateSystem();
}

void APlayerTankPawn::Move(float inputValue)
{
	if (inputValue <= 0 && trailParticleSystem->IsActive())
	{
		trailParticleSystem->DeactivateSystem();
	}
	else if (inputValue > 0 && trailParticleSystem->IsActive() == false)
	{
		trailParticleSystem->ActivateSystem();
	}

	FVector deltaLocation = FVector::ZeroVector;
	deltaLocation.X = inputValue * m_speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(deltaLocation, true);
}

void APlayerTankPawn::Rotate(float inputValue)
{
	FRotator deltaRocation = FRotator::ZeroRotator;
	deltaRocation.Yaw = inputValue * m_rotationSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(deltaRocation, true);
}
