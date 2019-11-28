// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShotNFall/ShotNFallGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShotNFallGameMode() {}
// Cross Module References
	SHOTNFALL_API UFunction* Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ShotNFall();
	SHOTNFALL_API UClass* Z_Construct_UClass_AShotNFallCharacter_NoRegister();
	SHOTNFALL_API UClass* Z_Construct_UClass_AShotNFallGameMode_NoRegister();
	SHOTNFALL_API UClass* Z_Construct_UClass_AShotNFallGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	SHOTNFALL_API UFunction* Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SHOTNFALL_API UClass* Z_Construct_UClass_ASNFAIController_NoRegister();
	SHOTNFALL_API UClass* Z_Construct_UClass_ASNF_PlatformBuilder_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics
	{
		struct _Script_ShotNFall_eventOnFall_Parms
		{
			AShotNFallCharacter* FallenCharacter;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FallenCharacter;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::NewProp_FallenCharacter = { UE4CodeGen_Private::EPropertyClass::Object, "FallenCharacter", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_ShotNFall_eventOnFall_Parms, FallenCharacter), Z_Construct_UClass_AShotNFallCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::NewProp_FallenCharacter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ShotNFall, "OnFall__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_ShotNFall_eventOnFall_Parms), Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void AShotNFallGameMode::StaticRegisterNativesAShotNFallGameMode()
	{
		UClass* Class = AShotNFallGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetRespawnTimer", &AShotNFallGameMode::execSetRespawnTimer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics
	{
		struct ShotNFallGameMode_eventSetRespawnTimer_Parms
		{
			AShotNFallCharacter* CharacterToRespawn;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CharacterToRespawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::NewProp_CharacterToRespawn = { UE4CodeGen_Private::EPropertyClass::Object, "CharacterToRespawn", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ShotNFallGameMode_eventSetRespawnTimer_Parms, CharacterToRespawn), Z_Construct_UClass_AShotNFallCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::NewProp_CharacterToRespawn,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShotNFallGameMode, "SetRespawnTimer", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(ShotNFallGameMode_eventSetRespawnTimer_Parms), Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AShotNFallGameMode_NoRegister()
	{
		return AShotNFallGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AShotNFallGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharactersPool_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_CharactersPool;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CharactersPool_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Platforms_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Platforms;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Platforms_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RespawnTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RespawnTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumberOfBots_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NumberOfBots;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CenterLevelLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CenterLevelLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AIClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_AIClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_CharacterClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LevelBuilderClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_LevelBuilderClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShotNFallGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ShotNFall,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AShotNFallGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AShotNFallGameMode_SetRespawnTimer, "SetRespawnTimer" }, // 2546786237
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ShotNFallGameMode.h" },
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharactersPool_MetaData[] = {
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharactersPool = { UE4CodeGen_Private::EPropertyClass::Array, "CharactersPool", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000000, 1, nullptr, STRUCT_OFFSET(AShotNFallGameMode, CharactersPool), METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharactersPool_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharactersPool_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharactersPool_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "CharactersPool", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AShotNFallCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_Platforms_MetaData[] = {
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_Platforms = { UE4CodeGen_Private::EPropertyClass::Array, "Platforms", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000000, 1, nullptr, STRUCT_OFFSET(AShotNFallGameMode, Platforms), METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_Platforms_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_Platforms_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_Platforms_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Platforms", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_RespawnTime_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_RespawnTime = { UE4CodeGen_Private::EPropertyClass::Float, "RespawnTime", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000010001, 1, nullptr, STRUCT_OFFSET(AShotNFallGameMode, RespawnTime), METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_RespawnTime_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_RespawnTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_NumberOfBots_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_NumberOfBots = { UE4CodeGen_Private::EPropertyClass::Int, "NumberOfBots", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000010001, 1, nullptr, STRUCT_OFFSET(AShotNFallGameMode, NumberOfBots), METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_NumberOfBots_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_NumberOfBots_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CenterLevelLocation_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CenterLevelLocation = { UE4CodeGen_Private::EPropertyClass::Struct, "CenterLevelLocation", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000010001, 1, nullptr, STRUCT_OFFSET(AShotNFallGameMode, CenterLevelLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CenterLevelLocation_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CenterLevelLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_AIClass_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_AIClass = { UE4CodeGen_Private::EPropertyClass::Class, "AIClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010001, 1, nullptr, STRUCT_OFFSET(AShotNFallGameMode, AIClass), Z_Construct_UClass_ASNFAIController_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_AIClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_AIClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharacterClass_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharacterClass = { UE4CodeGen_Private::EPropertyClass::Class, "CharacterClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010001, 1, nullptr, STRUCT_OFFSET(AShotNFallGameMode, CharacterClass), Z_Construct_UClass_AShotNFallCharacter_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharacterClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharacterClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_LevelBuilderClass_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "ShotNFallGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_LevelBuilderClass = { UE4CodeGen_Private::EPropertyClass::Class, "LevelBuilderClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010001, 1, nullptr, STRUCT_OFFSET(AShotNFallGameMode, LevelBuilderClass), Z_Construct_UClass_ASNF_PlatformBuilder_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_LevelBuilderClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_LevelBuilderClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShotNFallGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharactersPool,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharactersPool_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_Platforms,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_Platforms_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_RespawnTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_NumberOfBots,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CenterLevelLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_AIClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_CharacterClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallGameMode_Statics::NewProp_LevelBuilderClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShotNFallGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShotNFallGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShotNFallGameMode_Statics::ClassParams = {
		&AShotNFallGameMode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008802A8u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AShotNFallGameMode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AShotNFallGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AShotNFallGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShotNFallGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShotNFallGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShotNFallGameMode, 981075740);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShotNFallGameMode(Z_Construct_UClass_AShotNFallGameMode, &AShotNFallGameMode::StaticClass, TEXT("/Script/ShotNFall"), TEXT("AShotNFallGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShotNFallGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
