// Copyright YuhangPark


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor *Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	// IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(Target);
	// if (ASCInterface)
	// {
	// 	ASCInterface->GetAbilitySystemComponent(); // GAS提供了静态函数的方式
	// }

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	// TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, );
	// TargetASC->ApplyGameplayEffectSpecToSelf();

}

