#pragma once

#include "CoreMinimal.h"
#include "GameFrameWork/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "A_PrimitiveFountain.generated.h"

UCLASS()
class PUSHACTOR_API AA_PrimitiveFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	AA_PrimitiveFountain();

protected:
	virtual void BeginPlay() override;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    TSubclassOf<AActor> ParticleClass;   //����Ķ���
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    float ParticleSpawnInterval;         //����һ��
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    float InitialMinSpeed;                  //��ʼ��С�ٶ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    float InitialMaxSpeed;                  //��ʼ����ٶ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    int32 ParticlesPerBurst;             //һ������ٸ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    float ConeAngle;                    //����Ƕ�

private:
    FTimerHandle FireTimerHandle;       //��ʱ�����
    void GenerateParticles();
};
