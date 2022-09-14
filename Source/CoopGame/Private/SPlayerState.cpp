// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerState.h"




void ASPlayerState::AddScore(float ScoreDelta)
{
	Score += ScoreDelta;
}

void ASPlayerState::AddDeath(float DeathDelta)
{
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red, TEXT("OK3"));
	DeathCnt += DeathDelta;
}

int ASPlayerState::GetDeath()
{
	return DeathCnt;
}

int ASPlayerState::GetScore()
{
	return Score;
}

