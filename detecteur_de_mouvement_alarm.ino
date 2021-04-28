#define pinSensor 2
#define pinLed 13
#define pinBuzzer 12
int pirSensor =0;

void setup()
{
  pinMode(pinSensor, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
}

void loop()
{
  
  pirSensor = digitalRead(pinSensor);
  if (pirSensor == HIGH)
  {
  
     digitalWrite(pinLed, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pinLed, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
    tone(pinBuzzer, 1000, 500);
    
  
  }
  
  else {
    
    digitalWrite(pinLed, LOW);
  }
  
  delay(10);
}
