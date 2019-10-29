// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShotNFall/ShotNFallCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShotNFallCharacter() {}
// Cross Module References
	SHOTNFALL_API UClass* Z_Construct_UClass_AShotNFallCharacter_NoRegister();
	SHOTNFALL_API UClass* Z_Construct_UClass_AShotNFallCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_ShotNFall();
	SHOTNFALL_API UFunction* Z_Construct_UFunction_AShotNFallCharacter_IsFiring();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SHOTNFALL_API UClass* Z_Construct_UClass_ASNFBasicWeapon_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void AShotNFallCharacter::StaticRegisterNativesAShotNFallCharacter()
	{
		UClass* Class = AShotNFallCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsFiring", &AShotNFallCharacter::execIsFiring },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics
	{
		struct ShotNFallCharacter_eventIsFiring_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ShotNFallCharacter_eventIsFiring_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ShotNFallCharacter_eventIsFiring_Parms), &Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "ShotNFallCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShotNFallCharacter, "IsFiring", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(ShotNFallCharacter_eventIsFiring_Parms), Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AShotNFallCharacter_IsFiring()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AShotNFallCharacter_IsFiring_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AShotNFallCharacter_NoRegister()
	{
		return AShotNFallCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AShotNFallCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StarterWeaponSocketName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_StarterWeaponSocketName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StarterWeaponClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_StarterWeaponClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SideViewCameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SideViewCameraComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShotNFallCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ShotNFall,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AShotNFallCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AShotNFallCharacter_IsFiring, "IsFiring" }, // 2284712271
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ShotNFallCharacter.h" },
		{ "ModuleRelativePath", "ShotNFallCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponSocketName_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "ShotNFallCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponSocketName = { UE4CodeGen_Private::EPropertyClass::Name, "StarterWeaponSocketName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000010001, 1, nullptr, STRUCT_OFFSET(AShotNFallCharacter, StarterWeaponSocketName), METADATA_PARAMS(Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponSocketName_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponSocketName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponClass_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "ShotNFallCharacter.h" },
		{ "ToolTip", "Class of weapon which spawns at the start of the game" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponClass = { UE4CodeGen_Private::EPropertyClass::Class, "StarterWeaponClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010001, 1, nullptr, STRUCT_OFFSET(AShotNFallCharacter, StarterWeaponClass), Z_Construct_UClass_ASNFBasicWeapon_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ShotNFallCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera beside the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_CameraBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CameraBoom", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AShotNFallCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_CameraBoom_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_SideViewCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ShotNFallCharacter.h" },
		{ "ToolTip", "Side view camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_SideViewCameraComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SideViewCameraComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AShotNFallCharacter, SideViewCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_SideViewCameraComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_SideViewCameraComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShotNFallCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponSocketName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_StarterWeaponClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShotNFallCharacter_Statics::NewProp_SideViewCameraComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShotNFallCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShotNFallCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShotNFallCharacter_Statics::ClassParams = {
		&AShotNFallCharacter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AShotNFallCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AShotNFallCharacter_Statics::PropPointers),
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AShotNFallCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AShotNFallCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShotNFallCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShotNFallCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShotNFallCharacter, 1138529723);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShotNFallCharacter(Z_Construct_UClass_AShotNFallCharacter, &AShotNFallCharacter::StaticClass, TEXT("/Script/ShotNFall"), TEXT("AShotNFallCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShotNFallCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
