// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

AGoalTriggerBox::AGoalTriggerBox()
{

}
void AGoalTriggerBox::BeginPlay()
{
    Super::BeginPlay();
    Ball = dynamic_cast<ABall*>(ActorToCheck);

}

void AGoalTriggerBox::OverlapBeginAction()
{
    if (Ball) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("AGoalTriggerBox: Ball Overlap Begin"));
        IsBallInGoal = true;
        Ball->SetCanBallBeSummoned(false);
        Ball->SetCanBeTeleportedTo(false);
    }
}


void AGoalTriggerBox::OverlapEndAction()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("AGoalTriggerBox: Ball Overlap End"));
    if (Ball) {
        IsBallInGoal = false;
        Ball->SetCanBallBeSummoned(true);
        Ball->SetCanBeTeleportedTo(true);
    }
}

