/// Using Arduino Genuino
/// Inital set up using analog PIN 0, didital pins marked with ~ can also be used

#include <SparkFun_Tlc5940.h>
#include "Arduino.h"
#include "VibeMotor.h"
#include "MarkoSys.h"
#include "SoftwareSerial.h"


// -------- Bluetooth connection
SoftwareSerial mySerial(2, 3);
String rString;
bool isReading = false;
int arrayCount = 0;
String fbArray[8];
byte index = 0; // Index into array; where to store the character

// -------- Vib code
float startTime;
float i;
int DUR = 4000;
boolean mode = true;


MarkoSys * systemManager; //Top level manager of the vibration motors

void setup() {
  Tlc.init();
  i = 4095;
  mySerial.begin(9600);
  Serial.begin(9600);
  Serial.write("Power On");
  pinMode(13,OUTPUT);
  systemManager = new MarkoSys();
}

void loop() 
{ 

  char inData[6]; // Allocate some space for the string
  char inChar = -1; // Where to store the character read
  String fullStr;
  byte index = 0; // Index into array; where to store the character

  if (index < 5)
  {
    
    while (mySerial.available() > 0)
    {        
        if(isReading == false){
          char c = (char)mySerial.read();  //gets one byte from serial buffer
    
            if (c == 's') {
              isReading = true;
              arrayCount = 0;
              Serial.println(c);

               for(int i=0; i<8; i++){
                fbArray[i] = "";
               }
            }
        }
        if(isReading == true){
          char c = mySerial.read();  //gets one byte from serial buffer
    
          if (c == ',') {
            Serial.println("delimeter "+ fbArray[arrayCount]);  
            arrayCount++;
            if(arrayCount >= 8){
              isReading = false;
              arrayCount = 0;
            }

          }  
          else {     
            fbArray[arrayCount] += c; //makes the string readString
          } 
       }
     }
  }
  
  systemManager->Update();
  

}


