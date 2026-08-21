#include <Arduino.h>
#define PS2_X   15
#define PS2_Y   2
#define SW      4
#define SERVO   13
#define RESOLUTION 12
#define CHANNEL 0
#define  FREQ    50

int min_width = 0.6/20  *pow(2, RESOLUTION);
int max_width = 2.5/20  *pow(2, RESOLUTION);
int value;
void setup() 
{
  pinMode(PS2_X, INPUT);
  pinMode(PS2_Y, INPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
  ledcSetup(CHANNEL, FREQ, RESOLUTION);
  ledcAttachPin(SERVO, CHANNEL);
}

void loop() 
{
    value=map(analogRead(PS2_Y),0,pow(2,RESOLUTION),min_width, max_width);
    Serial.printf("X: %d, Y: %d, SW: %d,映射后Y: %d\n", analogRead(PS2_X), analogRead(PS2_Y), digitalRead(SW),value);
    ledcWrite(CHANNEL, value);
    delay(100);
}


