// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ShotNFallCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Public/SNFBasicWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/TriggerBox.h"
#include "ShotNFallGameMode.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "ShotNFall.h"

AShotNFallCharacter::AShotNFallCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 700.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	AINavigationUpCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("AINavigationUp"));
	AINavigationUpCapsule->InitCapsuleSize(243.f, 533.f);
	AINavigationUpCapsule->SetupAttachment(RootComponent);

	AINavigationDownCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("AINavigationDown"));
	AINavigationDownCapsule->InitCapsuleSize(225.f, 255.f);
	AINavigationDownCapsule->SetupAttachment(RootComponent);


	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 960.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}


//////////////////////////////////////////////////////////////////////////
// Input
void AShotNFallCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AShotNFallCharacter::MoveRight);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AShotNFallCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AShotNFallCharacter::StopCrouch);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AShotNFallCharacter::StartWeaponFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AShotNFallCharacter::StopWeaponFire);
}

void AShotNFallCharacter::BeginPlay()
{

	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AShotNFallCharacter::OnHit);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AShotNFallCharacter::OnOverlapEnd);

	//Spawn weapon and attach it to character
	FVector WeaponLocation = GetMesh()->GetSocketLocation(StarterWeaponSocketName);
	FRotator WeaponRotation = GetMesh()->GetSocketRotation(StarterWeaponSocketName);
	FActorSpawnParameters WeaponSpawnParams;
	WeaponSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	WeaponSpawnParams.Owner = this;
	CurrentWeapon = GetWorld()->SpawnActor<ASNFBasicWeapon>(StarterWeaponClass, WeaponLocation, WeaponRotation, WeaponSpawnParams);
	CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, StarterWeaponSocketName);
}

void AShotNFallCharacter::MoveRight(float Value)
{
	if (Value > 0.f)
	{
		SetActorRotation(FRotator(0.f, -90.f, 0.f));
	}
	else if (Value < 0.f)
	{
		SetActorRotation(FRotator(0.f, 90.f, 0.f));
	}

	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);

}

void AShotNFallCharacter::StartCrouch()
{
	Crouch();
}

void AShotNFallCharacter::StopCrouch()
{
	UnCrouch();
}

void AShotNFallCharacter::StartWeaponFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StartFire();
	}
}

void AShotNFallCharacter::StopWeaponFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StopFire();
	}
}

void AShotNFallCharacter::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
	if (SurfaceType == SURFACE_PLATFORM)
	{
		PlatformCharacterStandsOn = OtherActor;

	}
}

void AShotNFallCharacter::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	ATriggerBox* Bounds = Cast<ATriggerBox>(OtherActor);
	if (Bounds)
	{
		OnFallen.Broadcast(this);
	}
}



