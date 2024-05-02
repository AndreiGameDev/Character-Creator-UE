// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadWriteValues.h"
#include "HAL/PlatformFileManager.h" // Core
#include "Misc/FileHelper.h" // Core

FString UReadWriteValues::ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
	//Check if file exists
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read string from file failed - File does not exist - '%s'"), *FilePath);
		return "";
	}

	FString ReString = "";
	// Try to load the file. Output goes to restring
	if (!FFileHelper::LoadFileToString(ReString, *FilePath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read string from file failed - Was not able to read file - '%s'"), *FilePath);
		return "";
	}
	//Returns output if succesfull through both boolean checkks
	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Reading file succeded - '%s'"), *FilePath);
	return ReString;
}

void UReadWriteValues::WriteStringFromFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage)
{
	//Attempt to write to the file
	if (!FFileHelper::SaveStringToFile(String, *FilePath)) {
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Writing string to file failed - was not able to write to file. - '%s'"), *FilePath);
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write to string fie succeded - '%s'"), *FilePath);
}
