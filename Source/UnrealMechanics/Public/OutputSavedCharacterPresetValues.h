// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OutputSavedCharacterPresetValues.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS()
class UNREALMECHANICS_API UOutputSavedCharacterPresetValues : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CharacterPreset")
	static TArray<FName> GetCharacterPresetNames(UDataTable* DataTable, bool& bOutSuccess, FString& outReportMessage);

	UFUNCTION(BlueprintCallable, Category = "CharacterPreset")
	static void SaveCharacterPreset(UDataTable* DataTable, FName PresetName, int32 HeadValue, int32 ChestValue, int32 LegsValue, int32 FeetValue, bool& bOutSuccess, FString& outReportMessage);

	UFUNCTION(BlueprintCallable, Category = "CharacterPreset")
	static void ExposeCostumisationValues(UDataTable* DataTable, FName PresetName, int32& headValue, int32& chestValue, int32& legsValue, int32& feetValue, bool& bOutSuccess, FString& outReportMessage);

	static bool IsRowNameValid(UDataTable* DataTable, FName rowname);

	static bool IsDataTableValid(UDataTable* dataTable);
};
	