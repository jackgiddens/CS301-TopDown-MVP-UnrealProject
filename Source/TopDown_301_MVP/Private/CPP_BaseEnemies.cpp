// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseEnemies.h"

// Sets default values
ACPP_BaseEnemies::ACPP_BaseEnemies()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
//void ACPP_BaseEnemies::BeginPlay()
//{
	//Super::BeginPlay();
	
//}

// Called every frame
//void ACPP_BaseEnemies::Tick(float DeltaTime)
//{
	//Super::Tick(DeltaTime);

//}

// Called to bind functionality to input
//void ACPP_BaseEnemies::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

//}

float ACPP_BaseEnemies::CalculateCurrentHealth(float Damage, uint8 DamageType, const TMap<uint8, float>& DamageTable)
{
	if (const float* Multiplier = DamageTable.Find(DamageType))
	{
		// Multiply damage by the found multiplier
		Damage *= *Multiplier;
	}

	CurrentHealth -= Damage;

	CurrentHealth = FMath::Clamp(CurrentHealth, 0.0f, MaxHealth);

	return Damage;
}