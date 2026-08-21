#include <Arduino.h>
#define RELAY_PIN 15

hw_timer_t* timer = NULL;//初始化定时器


void led_display()
{
  digitalWrite(RELAY_PIN, !digitalRead(RELAY_PIN));//翻转继电器状态
  
}
void setup() 
{
    pinMode(RELAY_PIN, OUTPUT);
    timer = timerBegin(0, 80, true);//初始化定时器，80为分频，true为上升沿触发
    timerAttachInterrupt(timer, led_display, true);//将定时器中断连接到led_display函数
    timerAlarmWrite(timer, 1000000, true);//设置定时器中断触发时间为1秒，true为重复触发
    timerAlarmEnable(timer);//启动定时器中断
}
  void loop() 
{
  
}

