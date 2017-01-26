/// Using Arduino Genuino
/// Inital set up using analog PIN 0, didital pins marked with ~ can also be used

#include <SparkFun_Tlc5940.h>
#include "Arduino.h"
#include "SoftwareSerial.h"


// --------  connection
SoftwareSerial mySerial(2, 3);
String rawData;
String rString;
bool isReading = false;
int arrayCount;
float fbArray[8];
float p_fbArray[8];
byte index = 0; // Index into array; where to store the character

// -------- Vib code
float startTime;
float i;
int DUR = 4000;
boolean mode = true;


//MarkoSys * systemManager; //Top level manager of the vibration motors

void setup() {
  Tlc.init();
  //i = 4095;
  mySerial.begin(9600);
  Serial.begin(9600);
  Serial.write("Power On");
  pinMode(13, OUTPUT);

  rawData = "";
  arrayCount = 0;

  //  systemManager = new MarkoSys();
  for (int i = 0; i < 8; i++)
  {
    fbArray[i] = 2;
  }
}

void loop()
{
  /*if (mySerial.available() > 0)
    {
    // Serial.println("Bluetooth Connected");
    }
    else {
    //  Serial.println("Not Connected");
    }*/

  if (mySerial.available() >= 8)
  {
    //char c = (char)mySerial.read();  //gets one byte from serial buffer
    //Serial.println(c);
    //Serial.println(fbArray[0]);
    char c = mySerial.read();
    if (c == 's')
    {
      //Serial.println("Packet received");
      arrayCount = 0;
      /*for (int i = 0; i < 8; i++)
        {
        fbArray[i] = 6;
        }*/
    }
    else if (c == ',') {

      //Serial.println("frrabA "+ (String)arrayCount +": "+ fbArray[0]);
      fbArray[arrayCount] = rawData.toFloat();
      arrayCount++;
      rawData = "";

    }
    else {
      rawData += c;
    }
  }

  if (arrayCount == 0) {

    for (int i = 1; i <= 8; i++) {

      if ((0.00 < fbArray[i]) && (fbArray[i] < 4.00))
      {
        Tlc.set(6, map(fbArray[1], 0, 2, 0, 4095));
        Tlc.set(0, map(fbArray[4], 0, 2, 0, 4095));
        Tlc.set(1, map(fbArray[5], 0, 2, 0, 4095));
        Tlc.set(2, map(fbArray[3], 0, 2, 0, 4095));
        Tlc.set(3, map(fbArray[6], 0, 2, 0, 4095));
        Tlc.set(4, map(fbArray[7], 0, 2, 0, 4095));
        Tlc.set(5, map(fbArray[2], 0, 2, 0, 4095));
        Tlc.set(15, map(fbArray[8], 0, 2, 0, 4095));
        Tlc.update();
        Serial.println("DATA " + (String)i + ": " + fbArray[i]);
      }
    }


  }
}
