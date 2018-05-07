// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardData.h"
#include "Card3D.generated.h"


UCLASS()
class CARDGAME_API ACard3D : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *Mesh;
	
public:	
	// Sets default values for this actor's properties
	ACard3D();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Texture)
	UTexture *CardImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Value)
	int32 FaceValue;

	UFUNCTION(BlueprintCallable, Category = Construct)
	void InitializeCardData(FCardTable Data);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UStaticMeshComponent *GetMesh() const { return Mesh; }
	
};
