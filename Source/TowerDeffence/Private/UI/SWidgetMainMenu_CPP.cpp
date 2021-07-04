// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/SWidgetMainMenu_CPP.h"
#include "UI/MainMenuHUD.h"

#define LOCTEXT_NAMESPACE "ShopUI"

void SWidgetMainMenu_CPP::Construct(const FArguments& InArgs)
{

	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;
	
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);

	const FText TittleText = LOCTEXT("GameTitle", "Project Y");
	const FText PlayGameText = LOCTEXT("PlayeTittle", "Play");
	const FText SettingsText = LOCTEXT("SettingsTitle", "Settings");
	const FText QuitText = LOCTEXT("QuitText", "Quit");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TittleTextStyle = ButtonTextStyle;
	TittleTextStyle.Size = 60.f;
	
	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(TittleTextStyle)
				.Text(TittleText)
				.Justification(ETextJustify::Center)
			]
			//Play Button
			+SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SWidgetMainMenu_CPP::OnPlayClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(PlayGameText)
					.Justification(ETextJustify::Center)
				]
			]
			//Settings Button
			+SVerticalBox::Slot()
            .Padding(ButtonPadding)
            [
                SNew(SButton)
                .OnClicked(this, &SWidgetMainMenu_CPP::OnPlayClicked)
                [
                    SNew(STextBlock)
                    .Font(ButtonTextStyle)
                    .Text(SettingsText)
                    .Justification(ETextJustify::Center)
                ]
            ]
            //Quit Button
            +SVerticalBox::Slot()
            .Padding(ButtonPadding)
            [
                SNew(SButton)
                .OnClicked(this, &SWidgetMainMenu_CPP::OnQuitClicked)
                [
                    SNew(STextBlock)
                    .Font(ButtonTextStyle)
                    .Text(QuitText)
                    .Justification(ETextJustify::Center)
                ]
            ]
		]
	];
}

FReply SWidgetMainMenu_CPP::OnPlayClicked() const
{
	if(OwningHUD.IsValid())
	{
		OwningHUD->RemoveMenu();
	}
	return FReply::Handled();
}

FReply SWidgetMainMenu_CPP::OnQuitClicked() const
{
	if(OwningHUD.IsValid())
	{
		if(APlayerController* PC = OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
