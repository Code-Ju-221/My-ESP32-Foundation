#include <Arduino.h>
#include<ESP32Servo.h>
#define PS2_X   15
#define PS2_Y   2
#define SW      4
#define SERVO   13
#define RESOLUTION 12
#define  FREQ    50

Servo servo;//定义Servo对象
int value;
void setup() 
{
  pinMode(PS2_X, INPUT);
  pinMode(PS2_Y, INPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
  ESP32PWM::allocateTimer(0);//配置硬件定时器
  servo.setPeriodHertz(FREQ);//设置频率
  servo.attach(SERVO,500,2500);//连接Servo
}

void loop() 
{
    value=map(analogRead(PS2_Y),0,pow(2,RESOLUTION),0,180);
    Serial.printf("X: %d, Y: %d, SW: %d,映射后Y: %d\n", analogRead(PS2_X), analogRead(PS2_Y), digitalRead(SW),value);
    servo.write(value);
    delay(100);
}


