// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AShotNFallCharacter;
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef SHOTNFALL_ShotNFallCharacter_generated_h
#error "ShotNFallCharacter.generated.h already included, missing '#pragma once' in ShotNFallCharacter.h"
#endif
#define SHOTNFALL_ShotNFallCharacter_generated_h

#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_9_DELEGATE \
struct _Script_ShotNFall_eventOnCharacterFallen_Parms \
{ \
	AShotNFallCharacter* FallenCharacter; \
}; \
static inline void FOnCharacterFallen_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterFallen, AShotNFallCharacter* FallenCharacter) \
{ \
	_Script_ShotNFall_eventOnCharacterFallen_Parms Parms; \
	Parms.FallenCharacter=FallenCharacter; \
	OnCharacterFallen.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStopWeaponFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StopWeaponFire(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartWeaponFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartWeaponFire(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopWeaponFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StopWeaponFire(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartWeaponFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartWeaponFire(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShotNFallCharacter(); \
	friend struct Z_Construct_UClass_AShotNFallCharacter_Statics; \
public: \
	DECLARE_CLASS(AShotNFallCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShotNFall"), NO_API) \
	DECLARE_SERIALIZER(AShotNFallCharacter)


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAShotNFallCharacter(); \
	friend struct Z_Construct_UClass_AShotNFallCharacter_Statics; \
public: \
	DECLARE_CLASS(AShotNFallCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShotNFall"), NO_API) \
	DECLARE_SERIALIZER(AShotNFallCharacter)


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShotNFallCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShotNFallCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShotNFallCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShotNFallCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShotNFallCharacter(AShotNFallCharacter&&); \
	NO_API AShotNFallCharacter(const AShotNFallCharacter&); \
public:


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShotNFallCharacter(AShotNFallCharacter&&); \
	NO_API AShotNFallCharacter(const AShotNFallCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShotNFallCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShotNFallCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShotNFallCharacter)


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(AShotNFallCharacter, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AShotNFallCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__AINavigationUpCapsule() { return STRUCT_OFFSET(AShotNFallCharacter, AINavigationUpCapsule); } \
	FORCEINLINE static uint32 __PPO__AINavigationDownCapsule() { return STRUCT_OFFSET(AShotNFallCharacter, AINavigationDownCapsule); } \
	FORCEINLINE static uint32 __PPO__StarterWeaponClass() { return STRUCT_OFFSET(AShotNFallCharacter, StarterWeaponClass); } \
	FORCEINLINE static uint32 __PPO__StarterWeaponSocketName() { return STRUCT_OFFSET(AShotNFallCharacter, StarterWeaponSocketName); } \
	FORCEINLINE static uint32 __PPO__CurrentWeapon() { return STRUCT_OFFSET(AShotNFallCharacter, CurrentWeapon); } \
	FORCEINLINE static uint32 __PPO__PlatformCharacterStandsOn() { return STRUCT_OFFSET(AShotNFallCharacter, PlatformCharacterStandsOn); }


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_PROLOG
#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_RPC_WRAPPERS \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_INCLASS \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_INCLASS_NO_PURE_DECLS \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShotNFall_Source_ShotNFall_ShotNFallCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
