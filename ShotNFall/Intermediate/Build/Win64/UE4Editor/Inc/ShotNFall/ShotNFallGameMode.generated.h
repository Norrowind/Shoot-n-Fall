// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AShotNFallCharacter;
#ifdef SHOTNFALL_ShotNFallGameMode_generated_h
#error "ShotNFallGameMode.generated.h already included, missing '#pragma once' in ShotNFallGameMode.h"
#endif
#define SHOTNFALL_ShotNFallGameMode_generated_h

#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_9_DELEGATE \
struct _Script_ShotNFall_eventOnFall_Parms \
{ \
	AShotNFallCharacter* FallenCharacter; \
}; \
static inline void FOnFall_DelegateWrapper(const FMulticastScriptDelegate& OnFall, AShotNFallCharacter* FallenCharacter) \
{ \
	_Script_ShotNFall_eventOnFall_Parms Parms; \
	Parms.FallenCharacter=FallenCharacter; \
	OnFall.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetRespawnTimer) \
	{ \
		P_GET_OBJECT(AShotNFallCharacter,Z_Param_CharacterToRespawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetRespawnTimer(Z_Param_CharacterToRespawn); \
		P_NATIVE_END; \
	}


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetRespawnTimer) \
	{ \
		P_GET_OBJECT(AShotNFallCharacter,Z_Param_CharacterToRespawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetRespawnTimer(Z_Param_CharacterToRespawn); \
		P_NATIVE_END; \
	}


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShotNFallGameMode(); \
	friend struct Z_Construct_UClass_AShotNFallGameMode_Statics; \
public: \
	DECLARE_CLASS(AShotNFallGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ShotNFall"), SHOTNFALL_API) \
	DECLARE_SERIALIZER(AShotNFallGameMode)


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_INCLASS \
private: \
	static void StaticRegisterNativesAShotNFallGameMode(); \
	friend struct Z_Construct_UClass_AShotNFallGameMode_Statics; \
public: \
	DECLARE_CLASS(AShotNFallGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ShotNFall"), SHOTNFALL_API) \
	DECLARE_SERIALIZER(AShotNFallGameMode)


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SHOTNFALL_API AShotNFallGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShotNFallGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SHOTNFALL_API, AShotNFallGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShotNFallGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SHOTNFALL_API AShotNFallGameMode(AShotNFallGameMode&&); \
	SHOTNFALL_API AShotNFallGameMode(const AShotNFallGameMode&); \
public:


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SHOTNFALL_API AShotNFallGameMode(AShotNFallGameMode&&); \
	SHOTNFALL_API AShotNFallGameMode(const AShotNFallGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SHOTNFALL_API, AShotNFallGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShotNFallGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShotNFallGameMode)


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__LevelBuilderClass() { return STRUCT_OFFSET(AShotNFallGameMode, LevelBuilderClass); } \
	FORCEINLINE static uint32 __PPO__CharacterClass() { return STRUCT_OFFSET(AShotNFallGameMode, CharacterClass); } \
	FORCEINLINE static uint32 __PPO__AIClass() { return STRUCT_OFFSET(AShotNFallGameMode, AIClass); } \
	FORCEINLINE static uint32 __PPO__CenterLevelLocation() { return STRUCT_OFFSET(AShotNFallGameMode, CenterLevelLocation); } \
	FORCEINLINE static uint32 __PPO__NumberOfBots() { return STRUCT_OFFSET(AShotNFallGameMode, NumberOfBots); } \
	FORCEINLINE static uint32 __PPO__RespawnTime() { return STRUCT_OFFSET(AShotNFallGameMode, RespawnTime); } \
	FORCEINLINE static uint32 __PPO__Platforms() { return STRUCT_OFFSET(AShotNFallGameMode, Platforms); } \
	FORCEINLINE static uint32 __PPO__CharactersPool() { return STRUCT_OFFSET(AShotNFallGameMode, CharactersPool); }


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_16_PROLOG
#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_PRIVATE_PROPERTY_OFFSET \
	ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_RPC_WRAPPERS \
	ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_INCLASS \
	ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_PRIVATE_PROPERTY_OFFSET \
	ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_INCLASS_NO_PURE_DECLS \
	ShotNFall_Source_ShotNFall_ShotNFallGameMode_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShotNFall_Source_ShotNFall_ShotNFallGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
