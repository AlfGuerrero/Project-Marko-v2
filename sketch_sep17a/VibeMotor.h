#ifndef VibeMotor_h
#define VibeMotor_h
#include "Arduino.h"

class VibeMotor
{
  public:
    VibeMotor(int pin, long on, long off);
    void Update(int dist);

  private:
    int vibPin;
    long OnTime;
    long OffTime;
    int vibVal;
    unsigned long previousMillis;
};

#endif
