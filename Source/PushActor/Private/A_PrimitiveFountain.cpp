#include "A_PrimitiveFountain.h"
#include "Components/PrimitiveComponent.h"

AA_PrimitiveFountain::AA_PrimitiveFountain()
{
	PrimaryActorTick.bCanEverTick = false;
	ParticleSpawnInterval = 1.0f;
	InitialMinSpeed = 100.0f;
	InitialMaxSpeed = 500.0f;
	ParticlesPerBurst = 10;
	ConeAngle = 45.0f;
}

void AA_PrimitiveFountain::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &AA_PrimitiveFountain::GenerateParticles, ParticleSpawnInterval, true);
}

void AA_PrimitiveFountain::GenerateParticles()
{
    if (ParticleClass)
    {
        FVector SpawnLocation = GetActorLocation();
        FRotator SpawnRotation = GetActorRotation();

        for (int32 i = 0; i < ParticlesPerBurst; ++i)
        {
            float RandomYaw = FMath::RandRange(-ConeAngle / 2, ConeAngle / 2);
            float RandomPitch = FMath::RandRange(-ConeAngle / 2, ConeAngle / 2);
            FRotator ProjectileRotation = UKismetMathLibrary::ComposeRotators(SpawnRotation, FRotator(RandomPitch, RandomYaw, 0.0f));
            FVector LaunchDirection = ProjectileRotation.Vector();

            float RandomSpeed = FMath::RandRange(InitialMinSpeed, InitialMaxSpeed);

            FVector RandomOffset = FVector(FMath::RandRange(-10.0f, 10.0f), FMath::RandRange(-10.0f, 10.0f), FMath::RandRange(-10.0f, 10.0f));
            FVector AdjustedSpawnLocation = SpawnLocation + RandomOffset;

            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = this;
            SpawnParams.Instigator = GetInstigator();

            AActor* Projectile = GetWorld()->SpawnActor<AActor>(ParticleClass, SpawnLocation, ProjectileRotation, SpawnParams);
            if (Projectile)
            {
                UPrimitiveComponent* ProjectileComponent = Cast<UPrimitiveComponent>(Projectile->GetRootComponent());
                if (ProjectileComponent)
                {
                    ProjectileComponent->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);   //将物体种类设置为ECC_PhysicsBody
                    ProjectileComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore); //将所有碰撞通道关闭
                    ProjectileComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block); //ECC_WorldStatic该通道会碰撞
                    ProjectileComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block); //ECC_WorldDynamic该通道会碰撞
                    ProjectileComponent->AddImpulse(LaunchDirection * RandomSpeed);
                }
            }
        }
    }
}

