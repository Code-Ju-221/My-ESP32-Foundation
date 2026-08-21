#define LED_PIN 12

void setup() 
{
  pinMode(LED_PIN,OUTPUT);
}

void loop() 
{
 for(int i=0;i<256;i++)
 {
    analogWrite(LED_PIN,i);
    delay(10); 
 }
 for(int i=255;i>=0;i--)
 {
    analogWrite(LED_PIN,i);
    delay(10); 
 }
}
