// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/SNFBasicProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Character.h"
#include "ShotNFall.h"

// Sets default values
ASNFBasicProjectile::ASNFBasicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	RootComponent = MeshComp;
	MeshComp->OnComponentHit.AddDynamic(this, &ASNFBasicProjectile::OnHit);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComp->SetCollisionObjectType(COLLISION_PROJECTILE);
	MeshComp->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECollisionResponse::ECR_Ignore);
	MeshComp->SetNotifyRigidBodyCollision(true);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projetile Movement"));
	ProjectileMovement->bRotationFollowsVelocity = true;
}

// Called when the game starts or when spawned
void ASNFBasicProjectile::BeginPlay()
{
	Super::BeginPlay();

}

//Push enemy 
void ASNFBasicProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	float PushForceApplied = GetActorForwardVector().Y *  PushForce;
	ACharacter* PushedCharacter = Cast<ACharacter>(OtherActor);
	if (PushedCharacter)
	{
		FVector PushVelocity(0.0f, PushForceApplied, 0.f);
		PushedCharacter->LaunchCharacter(PushVelocity, true, false);
	}
	Destroy();
}

// Called every frame
void ASNFBasicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASNFBasicProjectile::LaucnchProjectile(float Speed, FVector LaunchDirection)
{
	ProjectileMovement->SetVelocityInLocalSpace(LaunchDirection * Speed);
}

//Set actor which is ignored by projectile(prevents self-shooting while moving and shot team mates)
void ASNFBasicProjectile::SetIgnoredActor(AActor * IgnoredActor)
{
	UE_LOG(LogTemp, Warning, TEXT("IgnoredActor: %s"), *IgnoredActor->GetName())
	MeshComp->IgnoreActorWhenMoving(IgnoredActor, true);
}

