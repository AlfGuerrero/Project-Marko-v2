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
//<<<<<<< HEAD
//float fbArray[8];
int p_fbArray[8];
byte index = 0;
//=======
float fbArray[8];
int beltIndex[8] = {6, 0, 1, 2, 3, 4, 5, 15};
//byte index = 0; // Index into array; where to store the character

// -------- Vib code
//>>>>>>> cd09e21104191734e9b48157857223921437382b
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
    //Serial.println("TEST");
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

  //<<<<<<< HEAD
  if (arrayCount >= 8 && isReading == true) {
    //for (int i = 0; i < 8; i++) {
    //if ((0.00 < fbArray[i]) && (fbArray[i] < 2.00))
    //{
    // p_fbArray[i] = fbArray[i];
    /*
    Tlc.set(0, p_fbArray[4]);
    Tlc.set(1, p_fbArray[5]);
    Tlc.set(2, p_fbArray[3]);
    Tlc.set(3, p_fbArray[6]);
    Tlc.set(4, p_fbArray[7]);
    Tlc.set(5, p_fbArray[2]);
    Tlc.set(15, p_fbArray[8]);
    //Tlc.set(15, p_fbArray[8]);
    Tlc.update();*/

    Tlc.set(0, p_fbArray[3]);
    Tlc.set(1, p_fbArray[4]);
    Tlc.set(2, p_fbArray[2]);
    Tlc.set(3, p_fbArray[5]);
    Tlc.set(4, p_fbArray[6]);
    Tlc.set(5, p_fbArray[1]);
    Tlc.set(15, p_fbArray[7]);
    //Tlc.set(15, p_fbArray[8]);
    Tlc.update();

    
    //}
    //else
    //p_fbArray[i] = 2.0;
    //}
    for (int i = 0; i < 8; i++) {
      Serial.println("DATA " + (String)i + ": " + p_fbArray[i]);
    }

    isReading = false;
    //=======
    /*
    if (arrayCount == 0) {

      for (int i = 0; i < 8; i++) {

        if (fbArray[i] < 0.00) {
          Tlc.set(beltIndex[i], map(0, 0, 2, 0, 4095));
          Serial.println("DATA " + (String)i + ": rounded");
        } else if (fbArray[i] > 4.00) {
          Tlc.set(beltIndex[i], map(4, 0, 2, 0, 4095));
          Serial.println("DATA " + (String)i + ": rounded");
        } else
        {
          Tlc.set(beltIndex[i], map(fbArray[i], 0, 2, 0, 4095));
          /*Tlc.set(0, map(fbArray[4], 0, 2, 0, 4095));
            Tlc.set(1, map(fbArray[5], 0, 2, 0, 4095));
            Tlc.set(2, map(fbArray[3], 0, 2, 0, 4095));
            Tlc.set(3, map(fbArray[6], 0, 2, 0, 4095));
            Tlc.set(4, map(fbArray[7], 0, 2, 0, 4095));
            Tlc.set(5, map(fbArray[2], 0, 2, 0, 4095));
            Tlc.set(15, map(fbArray[8], 0, 2, 0, 4095));

        }
        //Serial.println("DATA " + (String)i + ": " + fbArray[i]);
        //Tlc.update();

        
        //>>>>>>> cd09e21104191734e9b48157857223921437382b
      }*/
    }
  }




