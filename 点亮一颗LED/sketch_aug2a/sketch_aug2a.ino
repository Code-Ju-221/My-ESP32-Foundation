int led_pin=12;
void setup()
  {
    
  }

void loop() 
{
    pinMode(led_pin,OUTPUT);
    digitalWrite(led_pin,HIGH);
    delay(1000);
    digitalWrite(led_pin,LOW);
    delay(1000);
} 
