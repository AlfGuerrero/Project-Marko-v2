#include "Arduino.h"
#include "MarkoSys.h"
#include "VibeMotor.h"

MarkoSys::MarkoSys()
 {
    motors = {	new VibeMotor(0, 0, 0), new VibeMotor(1, 0, 0), 
                   new VibeMotor(3, 0, 0), new VibeMotor(5, 0, 0), 
                   new VibeMotor(6, 0, 0), new VibeMotor(9, 0, 0),
                    new VibeMotor(10, 0, 0), new VibeMotor(11, 0, 0)};
 }

void MarkoSys::Update()
{
	for(int i = 0; i < sizeof(motors) - 1; i++)
	{
		motors[i].Update();
	}
}
