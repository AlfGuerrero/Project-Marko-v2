#ifndef VibeMotor_h
#define VibeMotor_h
#include "Arduino.h"

class VibeMotor
{
  public:
    VibeMotor(int pin, long on, long off);
    void Update();

  private:
    int vibPin;
    long OnTime;
    long OffTime;
    int vibState;
    unsigned long previousMillis;
};

#endif
