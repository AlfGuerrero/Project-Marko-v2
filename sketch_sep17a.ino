/// Using Arduino Genuino
/// Inital set up using analog PIN 0, didital pins marked with ~ can also be used
void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
}

void loop() {
  // Switch case manually controlled for observing behaviour of Vibe Motor
  switch(3){
    case 1: //Seemingly randomly modulates the vibration of the motor from medium intensity to off
      for(int i = 5; i < 10; i++)
      {
        //delay(1000);
        i++;
        Serial.println(i);
        analogWrite(A0,255*(i/10));
        
        if(i == 9)
        {
          i = 5;
        }
      }
      break;
     case 2: //Leaves the motor off, not vibrations
      analogWrite(A0,255*0);
      break;
     case 3: //Full power to the motor
      analogWrite(A0,255*1);
      break;
  }
  
}
