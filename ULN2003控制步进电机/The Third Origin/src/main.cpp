#include <Arduino.h>
#include <CheapStepper.h>

//创建对象
CheapStepper stepper{27,14,12,13};
bool moveClockwise = true;

void setup() 
{
  stepper.setRpm(10);//设置转速
  
  stepper.moveTo(moveClockwise,2048);//按照步数旋转，步数为2048是一圈，正为顺时针
  delay(1000);
  stepper.moveDegrees(moveClockwise,90);//按照角度旋转
}


void loop() 
{
  
}

