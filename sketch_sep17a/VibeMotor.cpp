#include "Arduino.h"
#include "VibeMotor.h"

VibeMotor::VibeMotor(int pin, long on, long off)
{
	vibPin = pin;
	pinMode(vibPin, OUTPUT);

	OnTime = on;
	OffTime = off;

	vibState = 255;
	previousMillis = 0;
}

void VibeMotor::Update()
{
	unsigned long currentMillis = millis();

	if((vibState == 255) && (currentMillis - previousMillis >= OnTime))
	{
		vibState = 0;
		previousMillis = currentMillis;
		analogWrite(vibPin, vibState);
	}
	else if((vibState == 0) && (currentMillis - previousMillis >= OffTime))
	{
		vibState = 255;
		previousMillis = currentMillis;
		analogWrite(vibPin, vibState);
	}
}
