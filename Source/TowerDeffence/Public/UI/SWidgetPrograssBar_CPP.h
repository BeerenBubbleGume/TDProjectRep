// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateExtras.h"
#include "SlateCore.h"

/**
 * 
 */
class TOWERDEFFENCE_API SWidgetPrograssBar_CPP : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SWidgetPrograssBar_CPP){}
	
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwningHUD)
	
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AMainMenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override {return true;};
	
};
