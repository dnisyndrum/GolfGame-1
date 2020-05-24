// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchTriggerBox.h"
#include "Engine/Engine.h"

ASwitchTriggerBox::ASwitchTriggerBox(){
	
}

void ASwitchTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	CallCount = 0;
}

void ASwitchTriggerBox::SwitchOff()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("trigger switch end"));
	int32 size = Switches.Num();
	for (int i = 0; i < size; i++)
	{
		Switches[i]->ActionOff();
	}
	if (CallCount == ReapeatNum) {
		World->GetTimerManager().ClearTimer(TimerHandleSwitchOff);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("clearing timer"));

	}
	CallCount++;
}

void ASwitchTriggerBox::SwitchOn()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("trigger switch begin"));
	int32 size = Switches.Num();
	for (int i = 0; i < size; i++)
	{
		Switches[i]->ActionOn();
	}
	if (CallCount == ReapeatNum) {
		World->GetTimerManager().ClearTimer(TimerHandleSwitchOn);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("clearing timer"));
	}
}

void ASwitchTriggerBox::OverlapBeginAction()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("on overlapbegin action"));
	if (CanOnlyBeTriggeredOnce && !HasPreviouslyBeenTriggeredBegin) {
		World->GetTimerManager().SetTimer(TimerHandleSwitchOn, this, &ASwitchTriggerBox::SwitchOn, OnEverySec, true, DelayTimeOn);
		HasPreviouslyBeenTriggeredBegin = true;
	}
}


void ASwitchTriggerBox::OverlapEndAction()
{
	if (CanOnlyBeTriggeredOnce && !HasPreviouslyBeenTriggeredEnd) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("on overlapend action"));

		World->GetTimerManager().SetTimer(TimerHandleSwitchOff, this, &ASwitchTriggerBox::SwitchOff, OffEverySec, true, DelayTimeOff + DelayTimeOn);
		HasPreviouslyBeenTriggeredEnd = true;
	}
}


