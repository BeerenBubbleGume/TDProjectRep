// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SWidgetShopUI_CPP.h"
#include "Blueprint/UserWidget.h"
#include "TDShopUWidget_CPP.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFFENCE_API UTDShopUWidget_CPP : public UUserWidget
{
	GENERATED_BODY()

public:

	UTDShopUWidget_CPP(const FObjectInitializer& ObjectInitializer);
	
	void SetContent(TSharedRef<SWidget> InContent);
	bool CheckMyWidget();

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
