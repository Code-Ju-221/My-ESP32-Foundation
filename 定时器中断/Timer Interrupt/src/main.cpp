#include <Arduino.h>
#include <Ticker.h>
#define LED1 2
#define LED2 4

/*hw_timer_t *timer_LED1=NULL;
hw_timer_t *timer_LED2=NULL;
void timer_LED1_Interrupt()
{
  digitalWrite(LED1,!digitalRead(LED1));
}
void timer_LED2_Interrupt()
{
  digitalWrite(LED2,!digitalRead(LED2));
}

void setup() 
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  timer_LED1=timerBegin(0,80,true);//初始化定时器
  timer_LED2=timerBegin(1,80,true);
  timerAttachInterrupt(timer_LED1,timer_LED1_Interrupt,true);//true代表边沿触发
  timerAttachInterrupt(timer_LED2,timer_LED2_Interrupt,true);
  //设置定时模式，即几秒触发中断
  timerAlarmWrite(timer_LED1,1000*1000,true);//单位是微秒，true代表是周期性的
  timerAlarmWrite(timer_LED2,3000*1000,false);
  //启动定时器 
  timerAlarmEnable(timer_LED1);
  timerAlarmEnable(timer_LED2);
}

void loop() 
{
  
}*/

//构造定时器对象
Ticker timer1;
Ticker timer2;
void toggle(int pin)
{
  digitalWrite(pin,!digitalRead(pin));
}

void setup() 
{ 
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  //配置定时器
  timer1.attach(0.5, toggle,LED1);
  timer2.once(3, toggle,LED2);
}
void loop() 
{


}

