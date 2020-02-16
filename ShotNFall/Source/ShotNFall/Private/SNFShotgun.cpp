// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/SNFShotgun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Public/SNFBasicProjectile.h"

ASNFShotgun::ASNFShotgun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	NumberOfBullets = 8;
	BulletPitchRate = 0.25f;

}

void ASNFShotgun::Fire()
{
	if (MeshComp)
	{
		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		FActorSpawnParameters ProjectileSpawnParams;
		ProjectileSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ProjectileSpawnParams.Owner = GetOwner();

		float BulletPitchDelta = BulletPitchRate * (NumberOfBullets / 2);
		for (size_t i = 0; i < NumberOfBullets; i++)
		{
			ASNFBasicProjectile* Projectile = GetWorld()->SpawnActor<ASNFBasicProjectile>(ProjectileClass, MuzzleLocation, FRotator::ZeroRotator, ProjectileSpawnParams);
			if (Projectile)
			{
				Projectile->SetIgnoredActor(GetOwner());
				
				FVector LaunchDirection = FVector(0.f, GetActorRightVector().Y, BulletPitchDelta);
				Projectile->LaucnchProjectile(FirePower, LaunchDirection);
				BulletPitchDelta -= BulletPitchRate;
			}
		}

		if (FireAnimation)
		{
			MeshComp->PlayAnimation(FireAnimation, false);
		}
		LastFireTime = GetWorld()->TimeSeconds;
	}
}
