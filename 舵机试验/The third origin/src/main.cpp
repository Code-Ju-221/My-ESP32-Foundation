#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVO_PIN 13
#define SERVO_MIN 500
#define SERVO_MAX 2500

Servo myServo;//定义舵机对象

void setup() 
{  
  //分配硬件定时器
  ESP32PWM::allocateTimer(0);
  //设置频率
  myServo.setPeriodHertz(50);
  //关联舵机到引脚
  myServo.attach(SERVO_PIN,500,2500);
 
  
}

void loop() 
{
  myServo.write(90);//舵机旋转到90度
  delay(2000);//延时2秒
  myServo.write(0);//舵机旋转到0度
  delay(2000);//延时2秒
  myServo.write(180);//舵机旋转到180度
  delay(2000);//延时2秒
}

