// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"
#include "SlateExtras.h"

/**
 * 
 */
class TOWERDEFFENCE_API SWidgetMainMenu_CPP : public SCompoundWidget
{
public:
	 SLATE_BEGIN_ARGS(SWidgetMainMenu_CPP){}
		
	 SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwningHUD)
		
	 SLATE_END_ARGS()

	 void Construct(const FArguments& InArgs);

	 TWeakObjectPtr<class AMainMenuHUD> OwningHUD;

	 FReply OnPlayClicked() const;
	 FReply OnQuitClicked() const;

	 virtual bool SupportsKeyboardFocus() const override {return true;};
};
