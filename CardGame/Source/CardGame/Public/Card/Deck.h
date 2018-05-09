// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardData.h"
#include "Deck.generated.h"

class UDataTable;
class ACard3D;

UCLASS()
class CARDGAME_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Table)
	UDataTable *CardTable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Deck)
	TArray<FCardTable> CardDeck;

	UPROPERTY(EditDefaultsOnly, Category = Card)
	TSubclassOf<ACard3D> Card;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Shuffle();

	void DrawCard();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
