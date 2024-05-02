// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteValues.generated.h"

/**
 * 
 */
UCLASS()
class UNREALMECHANICS_API UReadWriteValues : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*
	* Open a text file and read it's content
	* @param FilePath = file path to read from
	* @param bOutSuccess = Confirms whether the action has been a succes or not
	* @param OutInfoMessage = More information about the action's result
	* 
	* @return string from your file
	*/
	UFUNCTION(BlueprintCallable, Category = "ReadWrite File")
		static FString ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString & OutInfoMessage);
	
	/*
	* Open a text file and write inside it's content
	* @param FilePath = file path to read from
	* @param String = The string you want to write inside the file
	* @param bOutSuccess = Confirms whether the action has been a succes or not
	* @param OutInfoMessage = More information about the action's result
	*/
	UFUNCTION(BlueprintCallable, Category = "ReadWrite File")
		static void WriteStringFromFile(FString FilePath,FString String ,bool& bOutSuccess, FString& OutInfoMessage);
};
