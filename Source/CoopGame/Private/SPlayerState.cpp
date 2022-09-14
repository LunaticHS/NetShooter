// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerState.h"




void ASPlayerState::AddScore(float ScoreDelta)
{
	Score += ScoreDelta;
}

void ASPlayerState::AddDeath(float DeathDelta)
{
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