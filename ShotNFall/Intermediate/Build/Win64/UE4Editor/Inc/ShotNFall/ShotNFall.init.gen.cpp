// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShotNFall_init() {}
	SHOTNFALL_API UFunction* Z_Construct_UDelegateFunction_ShotNFall_OnCharacterFallen__DelegateSignature();
	SHOTNFALL_API UFunction* Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ShotNFall()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ShotNFall_OnCharacterFallen__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ShotNFall_OnFall__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/ShotNFall",
				PKG_CompiledIn | 0x00000000,
				0xDBC5A889,
				0xD86E19CC,
				SingletonFuncArray, ARRAY_COUNT(SingletonFuncArray),
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
