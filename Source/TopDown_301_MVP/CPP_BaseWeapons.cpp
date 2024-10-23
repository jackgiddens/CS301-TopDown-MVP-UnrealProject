// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BaseWeapons.h"
#include "Kismet/GameplayStatics.h"
#include "GetEnemyHealthInterface.h"

// Sets default values
ACPP_BaseWeapons::ACPP_BaseWeapons()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
//void ACPP_BaseWeapons::BeginPlay()
//{
	//Super::BeginPlay();
	
//}

// Called every frame
//void ACPP_BaseWeapons::Tick(float DeltaTime)
//{
	//Super::Tick(DeltaTime);

//}

void ACPP_BaseWeapons::GetClosestEnemy(TArray<AActor*> OverlappingActors)
{
    FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

    for (AActor* Actor : OverlappingActors)
    {
        if (IsValid(BP_TargetEnemy))
        {
            FVector ClosestEnemyLocation = BP_TargetEnemy->GetActorLocation();
            float ClosestEnemyDist = FVector::Dist(PlayerLocation, ClosestEnemyLocation);
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player Location: %f"), ClosestEnemyDist));

            FVector CurrentEnemyLocation = Actor->GetActorLocation();
            float CurrentEnemyDist = FVector::Dist(PlayerLocation, CurrentEnemyLocation);
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player Location: %f"), CurrentEnemyDist));

            if (ClosestEnemyDist > CurrentEnemyDist)
            {
                BP_TargetEnemy = Actor;
                //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Closest Enemy: %s"), *BP_TargetEnemy->GetName()));
            }
        }
        else
        {
            BP_TargetEnemy = Actor;
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Closest Enemy: %s"), *BP_TargetEnemy->GetName()));
        }
    }
}

void ACPP_BaseWeapons::GetStrongestEnemy(TArray<AActor*> OverlappingActors)
{
    FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

    for (AActor* Actor : OverlappingActors)
    {
        if (IsValid(BP_TargetEnemy))
        {
            if (BP_TargetEnemy->Implements<UGetEnemyHealthInterface>()) 
            {
                float BP_TargetEnemyHealth = IGetEnemyHealthInterface::Execute_GetEnemyHealth(BP_TargetEnemy);
                if (Actor->Implements<UGetEnemyHealthInterface>()) 
                {
                    float ActorHealth = IGetEnemyHealthInterface::Execute_GetEnemyHealth(Actor);

                    if (ActorHealth > BP_TargetEnemyHealth) 
                    {
                        BP_TargetEnemy = Actor;
                    }
                }
            }
        }
        else
        {
            BP_TargetEnemy = Actor;
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Closest Enemy: %s"), *BP_TargetEnemy->GetName()));
        }
    }
}