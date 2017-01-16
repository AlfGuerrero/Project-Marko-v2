  #include "Arduino.h"
#include "MarkoSys.h"
#include "VibeMotor.h"
#include <SparkFun_Tlc5940.h>

MarkoSys::MarkoSys()
{
  motors = new VibeMotor[8] {{0, 0, 0},{1, 0, 0},{3, 0, 0},{5, 0, 0},{6, 0, 0},{9, 0, 0},{10, 0, 0},{11, 0, 0}};
    //motor(0, 0, 0);
    /*, new VibeMotor(1, 0, 0), 
                   new VibeMotor(3, 0, 0), new VibeMotor(5, 0, 0), 
                   new VibeMotor(6, 0, 0), new VibeMotor(9, 0, 0),
                    new VibeMotor(10, 0, 0), new VibeMotor(11, 0, 0)};*/
 }

void MarkoSys::Update()
{
  Tlc.clear();
  Serial.println("MarkoSys Update Function");
	for(int i = 0; i < sizeof(motors) - 1; i++)
	{
    Serial.print("  For Vibe Motor ");
    Serial.println(i);
		motors[i].Update();
	}
 Tlc.update();
}