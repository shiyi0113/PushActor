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
    UStaticMeshComponent* Mesh;  //静态网格体
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    UMaterial* BaseMaterial;    //材质
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    FLinearColor Color;          //颜色
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    float Size;                  //大小
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Properties")
    float LifeSpan;             //生存时间
private:
    UMaterialInstanceDynamic* DynamicMaterialInstance; //动态材质实例
};
