// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthDeathSignature);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(UIMin = "0.0", UIMax = "500.0"))
	float MaximumHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentHealth = 0.f;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float damage);
	
	UPROPERTY(BlueprintAssignable)
	FHealthDeathSignature OnDeath;
		
};
