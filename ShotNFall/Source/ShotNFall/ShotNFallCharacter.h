// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShotNFallCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterFallen, AShotNFallCharacter*, FallenCharacter);

class ASNFBasicWeapon;
class UCapsuleComponent;

UCLASS(config=Game)
class AShotNFallCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* AINavigationUpCapsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* AINavigationDownCapsule;

protected:

	/** Class of weapon which spawns at the start of the game */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ASNFBasicWeapon>StarterWeaponClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName StarterWeaponSocketName;

	virtual void BeginPlay() override;

	/** Called for side to side input */
	void MoveRight(float Val);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/*To track current weapon which character handle*/
	ASNFBasicWeapon* CurrentWeapon;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	AShotNFallCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE UCapsuleComponent* GetAINavigationUpCapsule() const { return AINavigationUpCapsule; }

	FORCEINLINE UCapsuleComponent* GetAINavigationDownCapsule() const { return AINavigationDownCapsule; }

	FOnCharacterFallen OnFallen;

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void StartWeaponFire();

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void StopWeaponFire();

	void StartCrouch();

	void StopCrouch();




private:

};
