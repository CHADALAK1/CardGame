// Fill out your copyright notice in the Description page of Project Settings.

#include "Card3D.h"
#include "CardData.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ACard3D::ACard3D()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

}

void ACard3D::InitializeCardData(FCardTable Data)
{
	FaceValue = Data.FaceValue;
	CardImage = Data.Image;
	UMaterialInstanceDynamic *MI = UMaterialInstanceDynamic::Create(Mesh->GetMaterial(0), Mesh);
	if (MI)
	{
		Mesh->SetMaterial(0, MI);
		MI->SetTextureParameterValue("CardTexture", CardImage);
	}
}

// Called when the game starts or when spawned
void ACard3D::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard3D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

