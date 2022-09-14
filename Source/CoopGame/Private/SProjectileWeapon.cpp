// Fill out your copyright notice in the Description page of Project Settings.


#include "SProjectileWeapon.h"

void ASProjectileWeapon::Fire()
{
	// Trace the world, from pawn eyes to crosshair location

	/*if (GetLocalRole() < ROLE_Authority)
	{
		ServerFire();
	}*/

	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		if (ProjectileClass)
		{
			AActor* temp = GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzleLocation, EyeRotation, SpawnParams);
			FRotator rot =  MyOwner->GetActorRotation();
			TArray<UStaticMeshComponent*> Components; 
			UStaticMesh* StaticMesh = NULL;
			UStaticMeshComponent* StaticMeshComponent = NULL;
			temp->GetComponents<UStaticMeshComponent>(Components); 
			for (int32 i = 0; i < Components.Num(); i++) 
			{ 
				StaticMeshComponent = Components[i]; 
				StaticMesh = StaticMeshComponent->GetStaticMesh(); 
			}
			StaticMeshComponent->SetPhysicsLinearVelocity(rot.Vector() * 2000.0, 1, "None");
		}
	}
}
