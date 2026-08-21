#include <Arduino.h>




void setup() 
{
  Serial.begin(9600); 
  Serial2.begin(9600); 
}

void loop() 
{
  if (Serial.available()) 
  {
    char receivedChar = Serial.read(); 
    Serial2.write(receivedChar); 
  }
  if (Serial2.available()) 
  {
    char receivedChar = Serial2.read(); 
    Serial.write(receivedChar); 
  }


}

