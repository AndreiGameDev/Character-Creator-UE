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
	/// <summary>
	/// Saves character preset values and outputs them as a new array
	/// </summary>
	/// <param name="ArrayPresetRows">Reference to the Preset Array we are going to be using</param>
	/// <param name="PresetName">The name the preset values will be saved under.</param>
	/// <param name="HeadValue">The value for the head clothing part that we will be using</param>
	/// <param name="ChestValue">The value for the clothing body part that we will be using</param>
	/// <param name="LegsValue">The value for the legs clothing part that we will be using</param>
	/// <param name="FeetValue">The value for the legs clothing part that we will be using</param>
	/// <param name="outArrayPreset">Outputting changed array value so we can save the array in blueprint</param>
	/// <param name="bOutSuccess">Debug boolean that shows wether operation has been succesfull or not</param>
	/// <param name="outReportMessage">Debug message that shows more information about failure or succes of the operation</param>
	UFUNCTION(BlueprintCallable, Category = "CharacterPreset")
	static void SaveCharacterPreset(
		TArray<FCharacterPresetRow> ArrayPresetRows, 
		FName PresetName, 
		int32 HeadValue, 
		int32 ChestValue, 
		int32 LegsValue, 
		int32 FeetValue, 
		TArray<FCharacterPresetRow>& outArrayPreset,
		bool& bOutSuccess,
		FString& outReportMessage);

};
	