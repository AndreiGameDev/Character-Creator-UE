// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FCharacterPresetRow.generated.h"

/// <summary>
/// Character Preset Struct values that we will be using to save clothing parts and the name of the preset
/// </summary>
USTRUCT(BlueprintType)	
struct FCharacterPresetRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "PresetName", MakeStructureDefaultValue = "0"))
	FString PresetName;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "HeadValue", MakeStructureDefaultValue = "0"))
	int32 HeadValue;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ChestValue", MakeStructureDefaultValue = "0"))
	int32 ChestValue;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "LegsValue", MakeStructureDefaultValue = "0"))
	int32 LegsValue;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "FeetValue", MakeStructureDefaultValue = "0"))
	int32 FeetValue;

};
