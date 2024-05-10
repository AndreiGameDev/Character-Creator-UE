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
	static void SaveCharacterPreset(TArray<FCharacterPresetRow> ArrayPresetRows, FName PresetName, int32 HeadValue, int32 ChestValue, int32 LegsValue, int32 FeetValue, TArray<FCharacterPresetRow>& outArrayPreset,bool& bOutSuccess, FString& outReportMessage);

	static bool IsRowNameValid(UDataTable* DataTable, FName rowname);

	static bool IsDataTableValid(UDataTable* dataTable);
};
	