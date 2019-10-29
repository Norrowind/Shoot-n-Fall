// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShotNFallCharacter.generated.h"

class ASNFBasicWeapon;

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

protected:

	/** Class of weapon which spawns at the start of the game */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ASNFBasicWeapon>StarterWeaponClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName StarterWeaponSocketName;

	virtual void BeginPlay() override;

	/** Called for side to side input */
	void MoveRight(float Val);

	void StartCrouch();

	void StopCrouch();

	void StartWeaponFire();

	void StopWeaponFire();

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

	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool IsFiring();

private:

	bool bFiring;

};
