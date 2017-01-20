  #include "Arduino.h"
#include "MarkoSys.h"
#include "VibeMotor.h"

MarkoSys::MarkoSys()
{
  motors = new VibeMotor*[8];
  motors[0] = new VibeMotor(0, 0, 0);
  motors[1]= new VibeMotor(1, 0, 0);
  motors[2]= new VibeMotor(2, 0, 0);
  motors[3]= new VibeMotor(3, 0, 0);
  motors[4]= new VibeMotor(4, 0, 0);
  motors[5]= new VibeMotor(5, 0, 0);
  motors[6]= new VibeMotor(6, 0, 0);
  motors[7]= new VibeMotor(15, 0, 0);
    //motor(0, 0, 0);
    /*, new VibeMotor(1, 0, 0), 
                   new VibeMotor(3, 0, 0), new VibeMotor(5, 0, 0), 
                   new VibeMotor(6, 0, 0), new VibeMotor(9, 0, 0),
                    new VibeMotor(10, 0, 0), new VibeMotor(11, 0, 0)};*/
 }

void MarkoSys::Update(float data[])
{
  //Serial.println("MarkoSys Update Function");
	for(int i = 0; i < 8; i++)
	{
    //Serial.print("For Vibe Motor ");
    //Serial.println(i);
		motors[i]->Update(data[i]);
 
    //Serial.println((String)i +": "+ (String)data[i]);
      
	}
}
