#include"LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available()>0)//应该是检测第一个数据
  {
    delay(100);//延时等待数据传输完成
    lcd.clear();//清屏
    while(Serial.available()>0)
    {
      lcd.write(Serial.read());//如果缓冲区还有数据，就继续读取并显示
    }
  }
}
