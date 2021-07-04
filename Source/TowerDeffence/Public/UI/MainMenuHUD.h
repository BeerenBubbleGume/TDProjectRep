// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFFENCE_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
public:

	void ShowMenu();
	void RemoveMenu() const;
	void ShowMyHUD();
	void ShowHP();
	void RemoveShop();
	
protected:
	
	TSharedPtr<class SWidgetMainMenu_CPP> MenuWidget;
	TSharedPtr<class SWidget> MainMenuContener;

	TSharedPtr<class SWidgetShopUI_CPP> ShopUI;
	TSharedPtr<class SWidget> ShopUIContainer;

	TSharedPtr<class SWidgetPrograssBar_CPP> Bar_HP_SWidget;
	TSharedPtr<class SWidget> Bar_HP_Container;

	virtual void BeginPlay() override;
	
		
};
