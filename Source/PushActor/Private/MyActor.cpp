#include "MyActor.h"


AMyActor::AMyActor()
{

	PrimaryActorTick.bCanEverTick = false;
	//≥ı ºªØ Ù–‘
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Color = FLinearColor::White;
	Size = 1.0f;
	LifeSpan = 3.0f;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	if (BaseMaterial && Mesh) {
		DynamicMaterialInstance = UMaterialInstanceDynamic::Create(BaseMaterial, this);
		DynamicMaterialInstance->SetVectorParameterValue(TEXT("BaseColor"), Color);
		Mesh->SetMaterial(0, DynamicMaterialInstance);
		Mesh->SetWorldScale3D({ Size,Size,Size });
	}
	SetLifeSpan(LifeSpan);
}

