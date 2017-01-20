#include "Arduino.h"
#include "SparkFun_Tlc5940.h"
#include "VibeMotor.h"

VibeMotor::VibeMotor(int pin, long on, long off)
{
	vibPin = pin;
	pinMode(vibPin, OUTPUT);

	OnTime = on;
	OffTime = off;

	vibVal = 0;
	previousMillis = 0;
}

void VibeMotor::Update(float dist)
{
	/*unsigned long currentMillis = millis();

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
	}*/
  Tlc.clear();
  vibVal = map(dist, 0, 6, 0, 4095);// Assuming value sent from unity is between 0-100
  Serial.println(vibPin + ": "+vibVal);
  Tlc.set(vibPin,vibVal);
  Tlc.update();
}
