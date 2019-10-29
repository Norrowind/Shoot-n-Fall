// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/SNFBasicWeapon.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ASNFBasicWeapon::ASNFBasicWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

}

// Called when the game starts or when spawned
void ASNFBasicWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASNFBasicWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

