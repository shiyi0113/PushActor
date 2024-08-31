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
    TSubclassOf<AActor> ParticleClass;   //喷出的东西
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    float ParticleSpawnInterval;         //几秒一喷
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    float InitialMinSpeed;                  //初始最小速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    float InitialMaxSpeed;                  //初始最大速度
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    int32 ParticlesPerBurst;             //一次喷多少个
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
    float ConeAngle;                    //喷射角度

private:
    FTimerHandle FireTimerHandle;       //定时器句柄
    void GenerateParticles();
};
