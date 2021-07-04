// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SWidgetPrograssBar_CPP.h"

void SWidgetPrograssBar_CPP::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;

	const FVector2D HealthSize = FVector2D(500, 30);
	const FVector2D HealthPosition = FVector2D(4.f, 4.f);

	const FVector2D ManaSize = FVector2D(350, 30);
	const FVector2D ManaPosition = FVector2D(4.f, 36.f);

	const FVector2D GateHealthPosition = FVector2D(650.f, 10.f);
	const FVector2D GateHealthSize = FVector2D(700.f, 35);
	

	ChildSlot
	[
		SNew(SCanvas)
		+SCanvas::Slot()
		.Size(HealthSize)
		.Position(HealthPosition)
		[
			SNew(SProgressBar)
			.Percent(100.f)
			
		]
		+SCanvas::Slot()
		.Size(ManaSize)
		.Position(ManaPosition)
		[
			SNew(SProgressBar)
			.Percent(100.f)
		]
		+SCanvas::Slot()
		.Size(GateHealthSize)
		.Position(GateHealthPosition)
		[
			SNew(SProgressBar)
			.Percent(100.f)
		]
	];
}
