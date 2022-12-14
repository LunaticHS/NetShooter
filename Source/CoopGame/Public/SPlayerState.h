// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API ASPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	void AddScore(float ScoreDelta);

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	void AddDeath(float DeathDelta);

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	int GetScore();

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	int GetDeath();

	UPROPERTY(EditDefaultsOnly, Category = "PlayerState")
	int DeathCnt = 0;
	
};
