// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "PlayerTankPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerTankPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	APlayerTankPawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	void HandleOnDestroy();
	APlayerController* GetPlayerController() const { return playerController; }
	bool isAlive() { return m_isAlive; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	void Move(float inputValue);
	void Rotate(float inputValue);

private:
	UPROPERTY(VisibleAnywhere, Category = "Component");
	class USpringArmComponent* springArmComponent;
	UPROPERTY(VisibleAnywhere, Category = "Component");
	class UCameraComponent* cameraComponent;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	float m_speed;
	UPROPERTY(EditAnywhere, Category = "Parameters")
	float m_rotationSpeed = 45.0f;

	UPROPERTY(EditAnywhere, Category = "Visuals")
	class UParticleSystemComponent* trailParticleSystem;

	bool m_isAlive = true;

	APlayerController* playerController;
};
