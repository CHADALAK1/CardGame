// Fill out your copyright notice in the Description page of Project Settings.

#include "Deck.h"
#include "Card3D.h"


// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeck::BeginPlay()
{
	Super::BeginPlay();

	FString ContextString;
	for (auto &it : CardTable->GetRowNames())
		CardDeck.Add(*CardTable->FindRow<FCardTable>(it, ContextString));
	
	Shuffle();

	DrawCard();
}

void ADeck::Shuffle()
{
	int64 DateInSeconds = FDateTime::Now().ToUnixTimestamp();
	FRandomStream SRand = FRandomStream();
	SRand.Initialize(DateInSeconds);
	for (int32 i = CardDeck.Num() - 1; i > 0; i--) 
	{
		int32 j = FMath::FloorToInt(FMath::SRand() * (i + 1)) % CardDeck.Num();
		FCardTable temp = CardDeck[i];
		CardDeck[i] = CardDeck[j];
		CardDeck[j] = temp;
	}
}

void ADeck::DrawCard()
{
	ACard3D *card = GetWorld()->SpawnActor<ACard3D>(Card);
	if (card)
	{
		UE_LOG(LogTemp, Warning, TEXT("SPAWNED CARD"));
		card->InitializeCardData(CardDeck[0]);
		CardDeck.RemoveAt(0);
		CardDeck.Shrink();
	}
}

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

