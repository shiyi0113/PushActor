#pragma once

#include "CoreMinimal.h"
#include "Materials/Material.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "MyActor.generated.h"

UCLASS()
class PUSHACTOR_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();
protected:
	virtual void BeginPlay() override;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    UStaticMeshComponent* Mesh;  //��̬������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    UMaterial* BaseMaterial;    //����
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    FLinearColor Color;          //��ɫ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    float Size;                  //��С
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    float LifeSpan;             //����ʱ��
private:
    UMaterialInstanceDynamic* DynamicMaterialInstance; //��̬����ʵ��
};
