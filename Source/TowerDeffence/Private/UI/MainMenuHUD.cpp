// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuHUD.h"
#include "UI/SWidgetMainMenu_CPP.h"
#include "UI/SWidgetPrograssBar_CPP.h"
#include "UI/SWidgetShopUI_CPP.h"

void AMainMenuHUD::ShowMenu()
{
	if(GEngine && GEngine->GameViewport)
	{
		MenuWidget = SNew(SWidgetMainMenu_CPP).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MainMenuContener, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
		if(PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMainMenuHUD::RemoveMenu() const
{
	if(GEngine && GEngine->GameViewport && MainMenuContener.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MainMenuContener.ToSharedRef());
		if(PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AMainMenuHUD::ShowMyHUD()
{
	if(GEngine && GEngine->GameViewport)
	{
		ShopUI = SNew(SWidgetShopUI_CPP).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(ShopUIContainer, SWeakWidget).PossiblyNullContent(ShopUI.ToSharedRef()));
		if(PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMainMenuHUD::ShowHP()
{
	if(GEngine && GEngine->GameViewport)
	{
		Bar_HP_SWidget = SNew(SWidgetPrograssBar_CPP).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(Bar_HP_Container, SWeakWidget).PossiblyNullContent(Bar_HP_SWidget.ToSharedRef()));
		
	}
}

void AMainMenuHUD::RemoveShop()
{
	if(GEngine && GEngine->GameViewport && ShopUIContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(ShopUIContainer.ToSharedRef());
		if(PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowMenu();
}
