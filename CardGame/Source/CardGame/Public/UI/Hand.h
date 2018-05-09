// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Hand.generated.h"

class UCardUI;

/**
 * 
 */
UCLASS()
class CARDGAME_API UHand : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hand)
	TArray<UCardUI*> _Hand;
	
	
};