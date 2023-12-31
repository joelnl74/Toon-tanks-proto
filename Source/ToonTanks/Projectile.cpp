// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFrameWork/ProjectileMovementComponent.h"
#include "GameFrameWork/DamageType.h"
#include <Kismet/GameplayStatics.h>
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile mesh"));
	RootComponent = projectileMesh;

	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile movement"));
	projectileMovementComponent->MaxSpeed = 1300.0f;
	projectileMovementComponent->InitialSpeed = 1300.0f;

	trailParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Trail particle system"));
	trailParticleSystem->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	projectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::HandleOnHit);
	UGameplayStatics::PlaySoundAtLocation(this, projectileLaunchSound, GetActorLocation());
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::HandleOnHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, FVector normalImpulse, const FHitResult& Hit)
{
	AActor* myOwner = GetOwner();

	if (myOwner == nullptr)
	{
		Destroy();

		return;
	}

	AController* instigator = myOwner->GetInstigatorController();
	UClass* damageTypeClass = UDamageType::StaticClass();

	if (otherActor && otherActor != this && otherActor != myOwner)
	{
		UGameplayStatics::ApplyDamage(otherActor, damage, instigator, this, damageTypeClass);
	}

	if (hitParticleSystem)
	{
		UGameplayStatics::PlaySoundAtLocation(this, projectileHitSound, GetActorLocation());
		UGameplayStatics::SpawnEmitterAtLocation(this, hitParticleSystem, GetActorLocation(), GetActorRotation());
	}

	Destroy();
}
