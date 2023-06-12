// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void HandleOnHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, FVector normalImpulse, const FHitResult& Hit);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess= "true"))
	UStaticMeshComponent* projectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent* projectileMovementComponent;

	UPROPERTY(EditAnywhere)
	float damage = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Visuals")
	class UParticleSystem* hitParticleSystem;
	UPROPERTY(EditAnywhere, Category = "Visuals")
	class UParticleSystemComponent* trailParticleSystem;
	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* projectileLaunchSound;
	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* projectileHitSound;
};
