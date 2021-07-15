// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TDShopUWidget_CPP.h"


UTDShopUWidget_CPP::UTDShopUWidget_CPP(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UTDShopUWidget_CPP::SetContent(TSharedRef<SWidget> InContent)
{
	MyWidget = InContent;
}

bool UTDShopUWidget_CPP::CheckMyWidget()
{
	return MyWidget.IsValid();
}

TSharedRef<SWidget> UTDShopUWidget_CPP::RebuildWidget()
{
	APlayerController* ThisPC = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
	if (!ThisPC) return SNew(SWidgetShopUI_CPP);

	AMainMenuHUD* ShopMenuHUD = Cast<AMainMenuHUD>(ThisPC->GetHUD());
	if (!ShopMenuHUD) return SNew(SWidgetShopUI_CPP);

	return ShopMenuHUD->UShopWidget.ToSharedRef();
}
