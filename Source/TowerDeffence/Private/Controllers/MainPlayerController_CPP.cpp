// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/MainPlayerController_CPP.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "SequencerChannelTraits.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Characters/PlayerCharacter_CPP.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UI/MainMenuHUD.h"
#include "UI/TDShopUWidget_CPP.h"

AMainPlayerController_CPP::AMainPlayerController_CPP()
{
	bShowMouseCursor = true;
}

void AMainPlayerController_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainPlayerController_CPP::SpawnWidgets()
{
	//WidgetRef = CreateWidget<AMainMenuHUD>(this, UTDShopUWidget_CPP::StaticClass(), "ConstructionPreview");
	HUD_ShopMenu = WidgetRef;
}

void AMainPlayerController_CPP::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void AMainPlayerController_CPP::OpenMenu()
{
	if (AMainMenuHUD* AMenuHUD = Cast<AMainMenuHUD>(GetHUD()))
	{
		AMenuHUD->ShowMenu();
	}
}

void AMainPlayerController_CPP::OpenShop()
{
	if (AMainMenuHUD* AMenuHUD = Cast<AMainMenuHUD>(GetHUD()))
	{
		AMenuHUD->ShowMyHUD();
	}
	UE_LOG(LogTemp, Warning, TEXT("Open Shop"))
}

void AMainPlayerController_CPP::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Open Menu", IE_Released, this, &AMainPlayerController_CPP::OpenMenu);
	InputComponent->BindAction("Open ShopUI", IE_Released, this, &AMainPlayerController_CPP::OpenShop);
	InputComponent->BindAction("Move To Mouse Cursor", IE_Released, this, &AMainPlayerController_CPP::MoveToMouseCursor);

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AMainPlayerController_CPP::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AMainPlayerController_CPP::OnSetDestinationReleased);

	// support touch devices
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AMainPlayerController_CPP::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AMainPlayerController_CPP::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AMainPlayerController_CPP::OnResetVR);
}

void AMainPlayerController_CPP::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (APlayerCharacter_CPP* MyPawn = Cast<APlayerCharacter_CPP>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AMainPlayerController_CPP::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AMainPlayerController_CPP::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AMainPlayerController_CPP::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AMainPlayerController_CPP::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

void AMainPlayerController_CPP::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}