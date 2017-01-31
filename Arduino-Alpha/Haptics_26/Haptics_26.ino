/// Using Arduino Genuino
/// Inital set up using analog PIN 0, didital pins marked with ~ can also be used

#include <SparkFun_Tlc5940.h>
#include "Arduino.h"
#include "SoftwareSerial.h"

SoftwareSerial mySerial(2, 3);
String rawData;
String rString;
bool isReading = false;
int arrayCount;
//float fbArray[8];
int p_fbArray[8];
byte index = 0;
float startTime;
float i;
int DUR = 4000;
boolean mode = true;

void setup() {
  Tlc.init();
  mySerial.begin(9600);
  Serial.begin(19200);
  pinMode(13, OUTPUT);
  rawData = "";
  arrayCount = 0;
  for (int i = 0; i < 8; i++)
  {
    //fbArray[i] = 4;
    p_fbArray[i] = 4;
  }

 
  mySerial.flush();
}

void loop()
{
  if (mySerial.available() >= 8)
  {
    char c = mySerial.read();
    if (c == 's' && isReading == false)
    {
      
      arrayCount = 0;
      isReading = true;
      Serial.println(c);
    }
    /*else if (c == ',') {
      fbArray[arrayCount] = rawData.toFloat();
      arrayCount++;
      rawData = "";
      Serial.print(c);
      }*/
    else if (isReading == true) {
      p_fbArray[arrayCount] = ((String)c).toInt() * 1000;
      arrayCount++;
      //Serial.print(c);
    }
    mySerial.flush();
  }

  if (arrayCount >= 8 && isReading == true) {
    //for (int i = 0; i < 8; i++) {
    //if ((0.00 < fbArray[i]) && (fbArray[i] < 2.00))
    //{
    // p_fbArray[i] = fbArray[i];
    Tlc.set(6, p_fbArray[0]);
    Tlc.set(0, p_fbArray[3]);
    Tlc.set(1, p_fbArray[4]);
    Tlc.set(2, p_fbArray[2]);
    Tlc.set(3, p_fbArray[5]);
    Tlc.set(4, p_fbArray[7]);
    Tlc.set(5, p_fbArray[1]);
    Tlc.set(15, p_fbArray[7]);
    Tlc.update();

    isReading = false;
    //}
    //else
    //p_fbArray[i] = 2.0;
    //}
    for (int i = 0; i < 8; i++) {
      Serial.println("DATA " + (String)i + ": " + p_fbArray[i]);
    }
  }
}
