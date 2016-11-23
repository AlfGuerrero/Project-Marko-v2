#ifndef MarkoSys_h
#define MarkoSys_h
#include "Arduino.h"
#include "VibeMotor.h"

class MarkoSys
{
  public:
  	MarkoSys();
  	void Update();
  private:
  	VibeMotor motors[8];
};

#endif
