// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleOnDestroy();

protected:
	void RotateTurret(FVector lookAt);
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess= "true"))
	class UCapsuleComponent* capsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess= "true"))
	UStaticMeshComponent* baseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess= "true"))
	UStaticMeshComponent* gunMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess= "true"))
	USceneComponent* projectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Visuals")
	class UParticleSystem* deathParticleSystem;

	UPROPERTY(EditDefaultsOnly, Category = "Combat parameters")
	TSubclassOf<class AProjectile> projectileClass;

	UPROPERTY(EditAnywhere, Category = "Audio")
	class USoundBase* deathSound;
};
