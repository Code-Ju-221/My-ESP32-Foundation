#include <Arduino.h>
#define BUTTON 14
#define LED    2
/*void handle_interrupt()
{
  Serial.println("中断触发");
}

void setup() 
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(BUTTON),handle_interrupt,FALLING);
}

void loop() 
{
  
} */

volatile bool flag=false;
void ISR()
{
  flag=true;
  
}
void setup()
{
  pinMode(14,INPUT_PULLDOWN);
  pinMode(2,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON),ISR,FALLING);
}
void loop()
{
  if(flag==true)
  {
    digitalWrite(LED,HIGH);
    delay(2000);
    digitalWrite(LED,LOW);
    flag=false;
  }
  
}