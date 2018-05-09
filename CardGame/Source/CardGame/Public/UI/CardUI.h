// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardUI.generated.h"

class UImage;

/**
 * 
 */
UCLASS()
class CARDGAME_API UCardUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Card)
	UImage *Image;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Card)
	int32 FaceValue;
};
