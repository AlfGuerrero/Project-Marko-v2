#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
String rString;
bool isReading = false;
int arrayCount = 0;
String fbArray[8];

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  Serial.write("Power On");
  pinMode(13,OUTPUT);
}
/*
  char Comp(char* This) {


  if (strcmp(inData, This)  == 0) {
    for (int i = 0; i < 19; i++) {
      inData[i] = 0;
    }
    index = 0;
    return (0);
  }
  else {
    return (1);
  }
  }

*/
byte index = 0; // Index into array; where to store the character
void loop()
{ char inData[6]; // Allocate some space for the string
  char inChar = -1; // Where to store the character read
  String fullStr;
  byte index = 0; // Index into array; where to store the character

  if (index < 5)
  {
    
    while (mySerial.available() > 0)
    {
        /*
        inChar = mySerial.read(); // Read a character
        inData[index] = inChar; // Store it
        index++; // Increment where to write next
      
        inData[index] = '\0'; // Null terminate the string
        String str(inData);
        fullStr = str;
        //Serial.println(str);
      
        */
        
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
            //rString=""; //clears variable for new input
            arrayCount++;
            if(arrayCount >= 8){
              isReading = false;
              arrayCount = 0;
            }
            //data=""; 

          }  
          else {     
            fbArray[arrayCount] += c; //makes the string readString
            //fbArray[arrayCount] += c; //makes the string readString
          } 
       }
      
     }
      
    //Serial.println(fullStr);
    //digitalWrite(13,fullStr.toInt());
    
    
    
    //memset(inData, 0, sizeof inData);

  }

}

