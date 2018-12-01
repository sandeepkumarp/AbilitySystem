#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <AbilitySystemInterface.h>
#include "CharacterBase.generated.h"

class UAbilitySystemComponent;
class UGameplayAbility;
class UAttributeSetBase;

UCLASS()
class ABILITYSYSTEM_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	UAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	UAttributeSetBase* AttributeSetBaseComp;

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire);

private:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
