// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"
#include "SlateExtras.h"
#include "Controllers/TDConstructionInterface.h"
#include "Controllers/TDPreviewBuilding_CPP.h"

/**
 * 
 */
class TOWERDEFFENCE_API SWidgetShopUI_CPP : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SWidgetShopUI_CPP){}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwningHUD)

	SLATE_ARGUMENT(TWeakObjectPtr<ATDPreviewBuilding_CPP>, ConstructionPreviewRef)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AMainMenuHUD> OwningHUD;

	TWeakObjectPtr<ATDPreviewBuilding_CPP> ConstructionPreviewRef;

	FReply OnPlayClicked() const;
	FReply OnClickedByTower_1() const;
	
	virtual bool SupportsKeyboardFocus() const override {return true;}
};
