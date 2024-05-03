// Fill out your copyright notice in the Description page of Project Settings.


#include "OutputSavedCharacterPresetValues.h"
#include "Engine/DataTable.h" // Engine
#include "FCharacterPresetRow.h"

TArray<FName> UOutputSavedCharacterPresetValues::GetCharacterPresetNames(UDataTable* DataTable, bool& bOutSuccess, FString& outReportMessage)
{
	if (IsDataTableValid(DataTable) == false) {
		bOutSuccess = false;
		outReportMessage = "Data Tabe not valid";
		return TArray<FName>();
	}

	bOutSuccess = true;
	outReportMessage = "Character preset names retrieved successfully";
	return DataTable->GetRowNames();
}

void UOutputSavedCharacterPresetValues::SaveCharacterPreset(UDataTable* DataTable, FName PresetName, int32 inHeadValue, int32 inChestValue, int32 inLegsValue, int32 inFeetValue, bool& bOutSuccess, FString& outReportMessage)
{
	if (IsDataTableValid(DataTable) == false) {
		bOutSuccess = false;
		outReportMessage = "DataTable is null";
		return;
	}
	if (IsRowNameValid(DataTable, PresetName) == false) {
		return;
	}
	// Create a new row
	FCharacterPresetRow* NewRow = new FCharacterPresetRow();
	NewRow->HeadValue = inHeadValue;
	NewRow->ChestValue = inChestValue;
	NewRow->LegsValue = inLegsValue;
	NewRow->FeetValue = inFeetValue;

	// Add the row to the data table
	DataTable->AddRow(PresetName, *NewRow);

	bOutSuccess = true;
	outReportMessage = "Character preset saved successfully";
}

void UOutputSavedCharacterPresetValues::ExposeCostumisationValues(UDataTable* DataTable, FName PresetName, int32& headValue, int32& chestValue, int32& legsValue, int32& feetValue, bool& bOutSuccess, FString& outReportMessage)
{
	if (IsDataTableValid(DataTable) == false) {
		bOutSuccess = false;
		outReportMessage = "DataTable is null";
		return;
	}
	FCharacterPresetRow* infoRow = DataTable->FindRow<FCharacterPresetRow>(PresetName, "");
	if (infoRow == nullptr) {
		bOutSuccess = false;
		outReportMessage = "Row not found";
		return;
	}
	headValue = infoRow->HeadValue;
	chestValue = infoRow->ChestValue;
	legsValue = infoRow->LegsValue;
	feetValue = infoRow->FeetValue;

	bOutSuccess = true;
	outReportMessage = "Extracted Succesfully";
}

bool UOutputSavedCharacterPresetValues::IsRowNameValid(UDataTable* DataTable, FName rowname) {
	TArray<FName> rowNames = DataTable->GetRowNames();
	if (rowNames.Contains(rowname)) {
		return false;
	}

	return true;
}

bool UOutputSavedCharacterPresetValues::IsDataTableValid(UDataTable* dataTable)
{
	if (dataTable == nullptr) {
		return false;
	}
	else {
		return true;
	}
}




