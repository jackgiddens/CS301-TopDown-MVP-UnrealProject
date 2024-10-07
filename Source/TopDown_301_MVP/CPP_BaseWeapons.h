// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_BaseWeapons.generated.h"

UCLASS()
class TOPDOWN_301_MVP_API ACPP_BaseWeapons : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_BaseWeapons();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision");
	//class USphereComponent* SphereCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target");
	AActor* BP_TargetEnemy;

	UFUNCTION(BlueprintCallable)
	void GetClosestEnemy(TArray<AActor*> OverlappingActors);

	UFUNCTION(BlueprintCallable)
	void GetStrongestEnemy(TArray<AActor*> OverlappingActors);
};
