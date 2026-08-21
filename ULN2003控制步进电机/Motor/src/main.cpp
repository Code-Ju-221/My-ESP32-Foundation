#include <Arduino.h>

 #define  in_1  27
 #define  in_2  14
 #define  in_3  12
 #define  in_4  13
 
  int in_pin[4]={in_1,in_2,in_3,in_4};
  int delay_time=2;
  int degree=180;
  int count=2048/ 4 *  degree/360;
  void setup() 
{
  for(int i=0;i<4;i++)
  {
    pinMode(in_pin[i],OUTPUT);
  }
  for(int i=0;i<count;i++)
  {
    //单四拍模式
    digitalWrite(27,1);
    digitalWrite(14,0);
    digitalWrite(12,0);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,1);
    digitalWrite(12,0);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,1);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,0);
    digitalWrite(13,1);
    delay(delay_time);
}
    delay(1000);
  for(int i=0;i<count;i++)
  {
    //双四拍模式
    digitalWrite(27,1);
    digitalWrite(14,1);
    digitalWrite(12,0);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,1);
    digitalWrite(12,1);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,1);
    digitalWrite(13,1);
    delay(delay_time);

    digitalWrite(27,1);
    digitalWrite(14,0);
    digitalWrite(12,0);
    digitalWrite(13,1);
    delay(delay_time);
  }
  for(int i=0;i<count;i++)
  {
    //双四拍模式顺时针
    digitalWrite(27,1);
    digitalWrite(14,1);
    digitalWrite(12,0);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,1);
    digitalWrite(14,0);
    digitalWrite(12,0);
    digitalWrite(13,1);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,1);
    digitalWrite(13,1);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,1);
    digitalWrite(12,1);
    digitalWrite(13,0);
    delay(delay_time);
  }
  for(int i=0;i<count;i++)
  {
    //八拍模式
    digitalWrite(27,1);
    digitalWrite(14,0);
    digitalWrite(12,0);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,1);
    digitalWrite(14,1);
    digitalWrite(12,0);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,1);
    digitalWrite(12,0);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,1);
    digitalWrite(12,1);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,1);
    digitalWrite(13,0);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,1);
    digitalWrite(13,1);
    delay(delay_time);

    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,0);
    digitalWrite(13,1);
    delay(delay_time);

    digitalWrite(27,1);
    digitalWrite(14,0);
    digitalWrite(12,0);
    digitalWrite(13,1);
    delay(delay_time);
  }
    digitalWrite(27,0);
    digitalWrite(14,0);
    digitalWrite(12,0);
    digitalWrite(13,0);
    
}

void loop() 
{
  
}

