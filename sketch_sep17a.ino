/// Using Arduino Genuino
/// Inital set up using analog PIN 0, didital pins marked with ~ can also be used
//#include "Timer.h"

float startTime;
float i;
int DUR = 4000;
boolean mode = true;

void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  i = 0.0;
  startTime = -1;
}

void loop() {
  // Switch case manually controlled for observing behaviour of Vibe Motor
  switch(1){
    case 1: //Seemingly randomly modulates the vibration of the motor from medium intensity to off
      
      delay(15);
      i++;
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
          //Serial.println(bezierIncrease((millis()-startTime)/DUR )*(255*4));//(millis()-startTime)/2000);
          //analogWrite(A0,bezierIncrease((millis()-startTime)/DUR )*(1024));
          //TOP ROW
          Serial.println(int(1024 - (bezierIncrease((millis()-startTime)/DUR ))*(1024)) + " " + int(bezierIncrease((millis()-startTime)/DUR )*(255)*4));
          
          analogWrite(A1,1024 - (bezierIncrease((millis()-startTime)/DUR ))*(1024));
          analogWrite(A2,1024 - (bezierIncrease((millis()-startTime)/DUR ))*(1024));
          
          //MIDDLE ROW
          analogWrite(3,255 - (bezierIncrease((millis()-startTime)/DUR ))*(255));
          analogWrite(5,bezierIncrease((millis()-startTime)/DUR )*(255));
          analogWrite(6,bezierIncrease((millis()-startTime)/DUR )*(255));

          
          //BOTTOM ROW
          analogWrite(9,bezierIncrease((millis()-startTime)/DUR )*(255));
          analogWrite(10,bezierIncrease((millis()-startTime)/DUR )*(255));
          analogWrite(11,bezierIncrease((millis()-startTime)/DUR )*(255));
        }
        else
        {
          startTime = -1;
          //delay(500);
          mode = !mode;
        }

      }
      if(i == 100)
      {
        i = 0;
      }
      break;
     case 2: //Leaves the motor off, not vibrations
      //analogWrite(A0,255*0);
      break;
     case 3: //Full power to the motor
       analogWrite(A0,255*0.8);
       //analogWrite(A1,255*0.8);
       //analogWrite(A2,255*0.8);
       //analogWrite(3,255*0.8);
       //analogWrite(5,255*0.8);
       //analogWrite(6,255*0.8);
       analogWrite(9,255);
       //analogWrite(10,255*0.8);
       //analogWrite(11,255*0.8);
      break;
  }

}



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

