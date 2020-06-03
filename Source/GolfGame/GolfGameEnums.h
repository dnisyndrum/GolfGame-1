#pragma once
UENUM()

//Enumerators for the Light status: On, Off, Flicker, Dim, or Do nothing
enum class LightStatus: uint8
{
	LightsTurnOn    UMETA(DisplayName = "TurnOnLights"),
	LightsTurnOff    UMETA(DisplayName = "TurnOffLights"),
	LightsFlicker   UMETA(DisplayName = "FlickerLights"),
	LightsDim  UMETA(DisplayName = "DimLights"),
	LightsDoNothing  UMETA(DisplayName = "DoNothing")
};

UENUM()
//Enumerators for the Actor status: On, Off, Flicker, or Do nothing
enum class ActorHideShowStatus: uint8
{
	ActorsShow   UMETA(DisplayName = "ShowActors"),
	ActorsHide   UMETA(DisplayName = "HideActors"),
	ActorsFlicker   UMETA(DisplayName = "FlickerActors"),
	ActorsDoNothing  UMETA(DisplayName = "DoNothing")
	
};

