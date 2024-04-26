// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UClass()
class UNREALMECHANICS_API OutputArray : public uObject
{
    GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintCallable, Category = "My Nodes")
    static int32 SomeIntReturningFunction(FString Text, int32 Number, FString& TextOut);

};
