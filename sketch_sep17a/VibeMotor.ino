class VibeMotor
{
  int vibPin;
  long OnTime;
  long OffTime;

  int vibState; //0-255 percent power
  unsigned long previousMillis;
  
  public:
  VibeMotor(int pin, long on, long off)
  {
    vibPin = pin;
    pinMode(vibPin, OUTPUT);

    OnTime = on;
    OffTime = off;

    vibState = 0;
    previousMillis = 0;
    
    
  }

  void Update()
  {
    unsigned long currentMillis = millis();

    if((vibState == 255) && (currentMillis - previousMillis >= OnTime))
    {
      vibState = 0;
      previousMillis = currentMillis;
      analogWrite(vibPin, vibState);
    }
    else if((vibState == 0) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = 255;
      previousMillis = currentMillis;
      analogWrite(vibPin, vibState);
    }
    
  }
  
}

