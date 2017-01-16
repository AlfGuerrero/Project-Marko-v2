#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

void setup () {
  mySerial.begin(9600);
  Serial.begin(9600);
  Serial.print("Init...");
  pinMode(13, OUTPUT);
}


void loop() {

  if (mySerial.available()) {
    //Serial.println("Bluetooth Connection Established...");
   //Serial.println((char)mySerial.read())
   
    String test = (String)mySerial.read();
    Serial.println(test);
    if(test == "1"){
      digitalWrite(13, HIGH);
    }
    
  }

}
