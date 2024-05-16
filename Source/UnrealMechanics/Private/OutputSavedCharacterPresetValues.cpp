// Fill out your copyright notice in the Description page of Project Settings.



#include "OutputSavedCharacterPresetValues.h"
#include "Engine/DataTable.h" // Engine
#include "FCharacterPresetRow.h"

	

void UOutputSavedCharacterPresetValues::SaveCharacterPreset(
	TArray<FCharacterPresetRow> DataTable, 
	FName PresetName, 
	int32 inHeadValue, 
	int32 inChestValue, 
	int32 inLegsValue,
	int32 inFeetValue, 
	TArray<FCharacterPresetRow>& outArrayPreset,
	bool& bOutSuccess,
	FString& outReportMessage)
{
	// If there is a preset with this name inside the array, then return and output error message
	for (FCharacterPresetRow preset : DataTable) {
		if (preset.PresetName == PresetName) {
			bOutSuccess = false;
			outReportMessage = "Name is not valid, it already exists";
			return;
		}
	}

	FCharacterPresetRow* NewRow = new FCharacterPresetRow();
	NewRow->PresetName = PresetName.ToString();
	NewRow->HeadValue = inHeadValue;
	NewRow->ChestValue = inChestValue;
	NewRow->LegsValue = inLegsValue;
	NewRow->FeetValue = inFeetValue;

	DataTable.Add(*NewRow);
	outArrayPreset = DataTable;
	bOutSuccess = true;
	outReportMessage = "Character preset saved successfully";
}






