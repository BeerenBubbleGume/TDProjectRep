// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SWidgetShopUI_CPP.h"

#include "Controllers/BuildingsMaster/Towers/TD_StandartTower_CPP.h"
#include "Towers/BasicTower_CPP.h"

#define LOCTEXT_NAMESPACE "ShopUI"

void SWidgetShopUI_CPP::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;
	ConstructionPreviewRef = InArgs._ConstructionPreviewRef;
	
	const FMargin ContentPadding = FMargin(5.f, 5.f);
	const FMargin ButtonPadding = FMargin(5.f);

	const FVector2D ShopPossition = FVector2D(10.f, 20.f);
	const FVector2D ShopSize = FVector2D(500.f, 800.f);

	const FVector2D ShopInterfacePosition = FVector2D(0.f, 44.f);
	const FVector2D ShopInterfaceSize = FVector2D(240.f, 600.f);
	

	const FText TittleText = LOCTEXT("ShopTittle", "Shop Interface");
	const FText TowersShopText = LOCTEXT("TowersShopPage", "Tower's List");
	const FText CharactersShopText = LOCTEXT("CharactersShopPage", "Character's List");
	

	const FText Tower_1 = LOCTEXT("Tower_1", "Standart Tower");
	const FText Tower_2 = LOCTEXT("Tower_2", "Fire Tower");
	const FText Tower_3 = LOCTEXT("Tower_3", "Ice Tower");
	const FText Tower_4 = LOCTEXT("Tower_4", "Doom Tower");
	const FText Tower_5 = LOCTEXT("Tower_4", "Tower");

	const FText Wall_1 = LOCTEXT("Tower_4", "Standart Wall");
	const FText Wall_2 = LOCTEXT("Tower_4", "Crystal Wall");
	const FText Wall_3 = LOCTEXT("Tower_4", "Spirit Wall");
	const FText Wall_4 = LOCTEXT("Tower_4", "Electro Wall");

	const FText Trap_1 = LOCTEXT("Tower_4", "Standart Trap");
	const FText Trap_2 = LOCTEXT("Tower_4", "Standart Trap");
	const FText Trap_3 = LOCTEXT("Tower_4", "Standart Trap");
	const FText Trap_4 = LOCTEXT("Tower_4", "Standart Trap");
	

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 15.f;

	FSlateFontInfo TittleTextStyle = ButtonTextStyle;
	TittleTextStyle.Size = 10.f;
	
	ChildSlot
	[
		SNew(SCanvas)
		+SCanvas::Slot()
		.Size(ShopSize)
		.Position(ShopPossition)
		[
			SNew(SWrapBox)
			+SWrapBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.ContentPadding(ButtonPadding)
				[
					SNew(STextBlock)
					.Text(TowersShopText)
					.Font(ButtonTextStyle)
				]
			]
			+SWrapBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.ContentPadding(ButtonPadding)
				.OnClicked(this ,&SWidgetShopUI_CPP::OnPlayClicked)
				[
					SNew(STextBlock)
					.Text(CharactersShopText)
					.Font(ButtonTextStyle)
				]
			]
			+SWrapBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SBorder)
				.Padding(ButtonPadding)
				[
					SNew(STextBlock)
				]
			]
			]
			+SCanvas::Slot()
			.Position(ShopInterfacePosition)
			.Size(ShopInterfaceSize)
			[
			SNew(SVerticalBox)
			/*
			* Turrets Segment
			*/
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SBorder)
				[
					SNew(STextBlock)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.OnClicked(this ,&SWidgetShopUI_CPP::OnClickedByTower_1)
				[
					SNew(STextBlock)
					.Text(Tower_1)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.OnClicked(this ,&SWidgetShopUI_CPP::OnPlayClicked)
				[
					SNew(STextBlock)
					.Text(Tower_2)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.OnClicked(this ,&SWidgetShopUI_CPP::OnPlayClicked)
				[
					SNew(STextBlock)
					.Text(Tower_3)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.OnClicked(this ,&SWidgetShopUI_CPP::OnPlayClicked)
				[
					SNew(STextBlock)
					.Text(Tower_4)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.OnClicked(this ,&SWidgetShopUI_CPP::OnPlayClicked)
				[
					SNew(STextBlock)
					.Text(Tower_5)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			/*
			* Walls Segment
			*/
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SBorder)
				[
					SNew(STextBlock)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(Wall_1)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(Wall_2)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(Wall_3)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(Wall_4)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
					]
			]
			/*
			 * Traps Segment
			*/
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SBorder)
				[
					SNew(STextBlock)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(Trap_1)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(Trap_2)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(Trap_3)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(Trap_4)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
}

FReply SWidgetShopUI_CPP::OnPlayClicked() const
{
	if(OwningHUD.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Click to button"));	
	}
	return FReply::Handled();
}

FReply SWidgetShopUI_CPP::OnClickedByTower_1() const
{
	if(OwningHUD.IsValid())
	{
		ConstructionPreviewRef->ConstructBuilding(ATD_StandartTower_CPP::StaticClass());
	}
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
