// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "CardData.generated.h"

UENUM()
enum class ESuit : uint8
{
	E_Hearts,
	E_Diamonds,
	E_Clubs,
	E_Spades
};

USTRUCT(BlueprintType)
struct FCardTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CardData, meta = (ClampMin = "1", ClampMax = "13"))
	int32 FaceValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CardData)
	ESuit Suit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CardData)
	UTexture *Image;

};