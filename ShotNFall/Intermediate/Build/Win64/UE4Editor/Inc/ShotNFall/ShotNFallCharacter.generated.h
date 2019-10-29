// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHOTNFALL_ShotNFallCharacter_generated_h
#error "ShotNFallCharacter.generated.h already included, missing '#pragma once' in ShotNFallCharacter.h"
#endif
#define SHOTNFALL_ShotNFallCharacter_generated_h

#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsFiring) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsFiring(); \
		P_NATIVE_END; \
	}


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsFiring) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsFiring(); \
		P_NATIVE_END; \
	}


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShotNFallCharacter(); \
	friend struct Z_Construct_UClass_AShotNFallCharacter_Statics; \
public: \
	DECLARE_CLASS(AShotNFallCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShotNFall"), NO_API) \
	DECLARE_SERIALIZER(AShotNFallCharacter)


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAShotNFallCharacter(); \
	friend struct Z_Construct_UClass_AShotNFallCharacter_Statics; \
public: \
	DECLARE_CLASS(AShotNFallCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShotNFall"), NO_API) \
	DECLARE_SERIALIZER(AShotNFallCharacter)


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_STANDARD_CONSTRUCTORS \
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


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShotNFallCharacter(AShotNFallCharacter&&); \
	NO_API AShotNFallCharacter(const AShotNFallCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShotNFallCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShotNFallCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShotNFallCharacter)


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(AShotNFallCharacter, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AShotNFallCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__StarterWeaponClass() { return STRUCT_OFFSET(AShotNFallCharacter, StarterWeaponClass); } \
	FORCEINLINE static uint32 __PPO__StarterWeaponSocketName() { return STRUCT_OFFSET(AShotNFallCharacter, StarterWeaponSocketName); }


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_11_PROLOG
#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_RPC_WRAPPERS \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_INCLASS \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_INCLASS_NO_PURE_DECLS \
	ShotNFall_Source_ShotNFall_ShotNFallCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShotNFall_Source_ShotNFall_ShotNFallCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
