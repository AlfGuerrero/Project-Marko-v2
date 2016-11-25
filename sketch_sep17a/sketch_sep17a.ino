#include <SparkFun_Tlc5940.h>


/// Using Arduino Genuino
/// Inital set up using analog PIN 0, didital pins marked with ~ can also be used
//#include "Timer.h"
#include "Arduino.h"
#include "VibeMotor.h"
#include "MarkoSys.h"

//Bluetooth Integration
const int BUFFER = 4;
int mRead[BUFFER] = {};

float startTime;
float i;
int DUR = 4000;
boolean mode = true;

void setupPWM16() {
    DDRB |= _BV(PB1) | _BV(PB2);        /* set pins as outputs */
    TCCR1A = _BV(COM1A1) | _BV(COM1B1)  /* non-inverting PWM */
        | _BV(WGM11);                   /* mode 14: fast PWM, TOP=ICR1 */
    TCCR1B = _BV(WGM13) | _BV(WGM12)
        | _BV(CS10);                    /* no prescaling */
    ICR1 = 0xffff;                      /* TOP counter value */
}

// Bluetooth Serial Communication Reading function
void BluetoothRead()
{
    
  if (Serial.read() == '255')
  {
    for (i = 0; i < BUFFER; i++)
    {
       mRead[BUFFER] = Serial.read();
    }
  }
    
}

/* 16-bit version of analogWrite(). Works only on pins 9 and 10. 
void analogWrite16(uint8_t pin, uint16_t val)
{
    switch (pin) {
        case  9: OCR1A = val; break;
        case 10: OCR1B = val; break;
    }
}
*/

MarkoSys systemManager; //Top level manager of the vibration motors

void setup() {
  Tlc.init();
  Serial.begin(9600);
  //sytemManager MarkoSys();
  //pinMode(A0,OUTPUT);
  /*pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  i = 0.0;
  startTime = -1;*/
}

void loop() 
{  //analogWriteResolution(8);
  
  systemManager.Update();
  
  // Switch case manually controlled for observing behaviour of Vibe Motor
  /*switch(1){
    case 1: //Seemingly randomly modulates the vibration of the motor from medium intensity to off
      
      delay(15);
      i++;
       
      Serial.println(i);
      analogWrite(0,i);
      analogWrite(1,i);
      analogWrite(3,i);
      analogWrite(5,i);
      analogWrite(6,i);
      analogWrite(9,i);
      analogWrite(10,i);
      analogWrite(11,i);*/
      
      //delay(1000);
      //Serial.println( bezierIncrease(i/100));
      /*if (startTime == -1)
      {
        startTime = millis();
      }
      else
      {
        if(millis() - startTime <= DUR )
        {
          //Serial.println(bezierIncrease((millis()-startTime)/DUR )*(255*4));//(millis()-startTime)/2000);
          //analogWrite(A0,bezierIncrease((millis()-startTime)/DUR )*(1024));
          //TOP ROW
          //Serial.println(int(1024 - (bezierIncrease((millis()-startTime)/DUR ))*(1024)));
          
          //analogWrite(A1,255 - (bezierIncrease((millis()-startTime)/DUR ))*(255));
          //analogWrite(A2,1023 - (bezierIncrease((millis()-startTime)/DUR ))*(1023));
          analogWrite(A2,1023);
       analogWrite(3,255);
       analogWrite(5,0);
       analogWrite(6,0);
       analogWrite(9,0);
       analogWrite(10,0);
       analogWrite(11,0);*/
          /*
          //MIDDLE ROW
          analogWrite(3,255 - (bezierIncrease((millis()-startTime)/DUR ))*(255));
          analogWrite(5,bezierIncrease((millis()-startTime)/DUR )*(255));
          analogWrite(6,bezierIncrease((millis()-startTime)/DUR )*(255));

          
          //BOTTOM ROW
          analogWrite(9,bezierIncrease((millis()-startTime)/DUR )*(255));
          analogWrite(10,bezierIncrease((millis()-startTime)/DUR )*(255));
          analogWrite(11,bezierIncrease((millis()-startTime)/DUR )*(255));*/
        /*}
        else
        {
          startTime = -1;
          //delay(500);
          mode = !mode;
        }

      }
      if(i == 1024)
      {
        i = 0;
      }
      break;
     case 2: //Leaves the motor off, not vibrations
       analogWrite(A0,1023);
       analogWrite(A1,1023);
       analogWrite(A2,1023);
       analogWrite(3,255);
       analogWrite(5,0);
       analogWrite(6,0);
       analogWrite(9,0);
       analogWrite(10,0);
       analogWrite(11,0);
      break;
     case 3: //Full power to the motor
       analogWrite(A0,0);
       analogWrite(A1,0);
       analogWrite(A2,0);
       analogWrite(3,0);
       analogWrite(5,255);
       analogWrite(6,255);
       analogWrite(9,255);
       analogWrite(10,255);
       analogWrite(11,255);
      break;
    case 4:
      delay(15);
      //i = 0;
      //delay(1000)
      //Serial.println( bezierIncrease(i/100));
      if (startTime == -1)
      {
        startTime = millis();
      }
      else
      {
        if(millis() - startTime <= DUR )
        {
          powerMotor(i);
        }
        else
        {
          startTime = -1;
          i++;
          //delay(500);
          mode = !mode;
        }

      }
      if(i == 9)
      {
        i = 0;
      }
      break;
  }*/

}


/*
float bezierIncrease (float t) {
    float y;
    int temp;
    temp = 1;
    if(mode == true)
      temp = 1;
    else
      temp = 4;
    
    switch(temp){
      case 1:
        y = pow((1 - t), 3);
        break;
        
      case 2:
        y = 3 * pow((1 - t), 2) * t;
        break;
        
      case 3:
        y = 3 * (1 - t) *  pow(t, 2);
        break;

      case 4:
        y = pow(t, 3);
        break;
    }
    
    return y;
}

void powerMotor( int motorNumber)
{
  if(motorNumber == 0)
  {
    Serial.print("powering 1");
    analogWrite(A0,1023 - (bezierIncrease((millis()-startTime)/DUR ))*(1023));
    analogWrite(A1,1023);
    analogWrite(A2,1023);
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(11,0);
    
  }
  if(motorNumber == 1)
  {
    Serial.print("powering 2");
    analogWrite(A1,1023 - (bezierIncrease((millis()-startTime)/DUR ))*(1023));
    analogWrite(A0,1023);
    analogWrite(A2,1023);
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(11,0); 
  }
  if(motorNumber == 2)
  {
    Serial.print("powering 3");
    analogWrite(A2,1023 - (bezierIncrease((millis()-startTime)/DUR ))*(1023));
    analogWrite(A0,1023);
    analogWrite(A1,1023);
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(11,0);
  }
  if(motorNumber == 3)
  {
    Serial.print("powering 4");
    analogWrite(3,255 - (bezierIncrease((millis()-startTime)/DUR ))*(255));
    analogWrite(A0,1023);
    analogWrite(A1,1023);
    analogWrite(A2,1023);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(11,0);
  }
  if(motorNumber == 4)
  {
    Serial.print("powering 5");
    analogWrite(5,bezierIncrease((millis()-startTime)/DUR )*(255));
    analogWrite(A0,1023);
    analogWrite(A1,1023);
    analogWrite(A2,1023);
    analogWrite(3,255);
    analogWrite(6,0);
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(11,0);
  }
  if(motorNumber == 5)
  {
    Serial.print("powering 6");
    analogWrite(6,bezierIncrease((millis()-startTime)/DUR )*(255));
    analogWrite(A0,1023);
    analogWrite(A1,1023);
    analogWrite(A2,1023);
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(11,0);
  }
  if(motorNumber == 6)
  {
    Serial.print("powering 7");
    analogWrite(9,bezierIncrease((millis()-startTime)/DUR )*(255));
    analogWrite(A0,1023);
    analogWrite(A1,1023);
    analogWrite(A2,1023);
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(10,0);
    analogWrite(11,0);
  }
  if(motorNumber == 7)
  {
    Serial.print("powering 8");
    analogWrite(10,bezierIncrease((millis()-startTime)/DUR )*(255));
    analogWrite(A0,1023);
    analogWrite(A1,1023);
    analogWrite(A2,1023);
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
    analogWrite(11,0);
  }
  if(motorNumber == 8)
  {
    Serial.print("powering 9");
    analogWrite(11,bezierIncrease((millis()-startTime)/DUR )*(255));
    analogWrite(A0,1023);
    analogWrite(A1,1023);
    analogWrite(A2,1023);
    analogWrite(3,255);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
    analogWrite(10,0);
  }
  Serial.println(" ");
  
}
*/
