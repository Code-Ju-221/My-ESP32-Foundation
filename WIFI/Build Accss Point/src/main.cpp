#include <Arduino.h>
#include <WiFi.h>
const char* ssid = "ESP32";
const char*password="12345678";
void setup() 
{
  Serial.begin(9600);
  WiFi.softAP(ssid, password);
  Serial.println("Access Point started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() 
{
 
}


