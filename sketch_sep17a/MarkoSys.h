#ifndef MarkoSys_h
#define MarkoSys_h
#include "Arduino.h"
#include "VibeMotor.h"

class MarkoSys
{
  public:
  	MarkoSys();
  	void Update(int data[]);
  private:
  	VibeMotor * motors;
};

#endif
