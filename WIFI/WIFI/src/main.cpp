#include <Arduino.h>
#include<WIFI.h>
//定义WIFI ID与PIN
const char*ssid="ChinaNet-b2Ti";
const char*password="mwi9m54v";
#define pin 2
void setup() 
{
  Serial.begin(9600);
  WiFi.begin(ssid,password);
  Serial.println("Connecting to WiFi");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("Connecting to WiFi");
    delay(1000);
  }
  Serial.println("Connected to WiFi");
  Serial.println("WIFI IP地址:");
 
  Serial.println(WiFi.localIP());
  pinMode(pin,OUTPUT);
  for(int i=0;i<3;i++)
  {
    digitalWrite(pin,HIGH);
    delay(1000);
    digitalWrite(pin,LOW);
    delay(1000);
  }
    digitalWrite(pin,LOW);
}

void loop() 
{
  
}

