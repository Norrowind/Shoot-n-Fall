// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/SNFBasicWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Public/SNFBasicProjectile.h"


// Sets default values
ASNFBasicWeapon::ASNFBasicWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

}

// Called when the game starts or when spawned
void ASNFBasicWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASNFBasicWeapon::Fire()
{
	if (MeshComp)
	{
		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		FActorSpawnParameters ProjectileSpawnParams;
		ProjectileSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ASNFBasicProjectile* Projectile = GetWorld()->SpawnActor<ASNFBasicProjectile>(ProjectileClass, MuzzleLocation, FRotator::ZeroRotator, ProjectileSpawnParams);
		if (Projectile)
		{
			Projectile->SetIgnoredActor(GetOwner());
			Projectile->LaucnchProjectile(FirePower, GetActorRightVector());
		}

		if (FireAnimation)
		{
			MeshComp->PlayAnimation(FireAnimation, false);
		}
	}
}

// Called every frame
void ASNFBasicWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

