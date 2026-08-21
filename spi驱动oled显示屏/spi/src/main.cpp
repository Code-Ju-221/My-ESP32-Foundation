#include <Arduino.h>
#include<SPI.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define SCREEN_WIDDTH 128
#define SCREEN_HEIGHT 64
#define OLED_MOSI     13
#define OLED_SCK      18
#define OLED_DC       2    
#define OLED_RESET    15
#define OLED_CS       4
//初始化进度变量
int progress = 0;

//构造对象
Adafruit_SSD1306 oled(SCREEN_WIDDTH, SCREEN_HEIGHT,OLED_MOSI,OLED_SCK,OLED_DC, OLED_RESET, OLED_CS);
void setup() 
{
  oled.begin();
  //oled.clearDisplay();
  //绘制一条直线
  //oled.drawFastHLine(0, 32, 128, WHITE);
  //oled.drawLine(0,0,128,32,WHITE);//draw a line from (0,0) to (128,32)
  //oled.drawRect(6,6,100,50,WHITE);//draw a rectangle with top left corner at (6,6) and width 100 and height 50
  //oled.fillRect(0,0,128,64,WHITE);//fill a rectangle with top left corner at (0,0) and width 128 and height 64
  /*oled.setTextColor(WHITE);//设置文字颜色为白色
  oled.setCursor(10,32);//设置文字起始位置
  oled.setTextSize(1.5);//设置文字大小为1倍
  oled.println("I am Ju Ruodi");//文字颜色默认是黑色
  oled.display();*/

}

void loop() 
{
     oled.clearDisplay();
     oled.setTextColor(WHITE);
     oled.setCursor(40,44);
    oled.println("progress...");




    oled.drawRoundRect(0,32,128,10,5,WHITE);
    oled.fillRoundRect(2,34,progress,6,2,WHITE);
    if(progress<122)
    {
      progress++;
    }
    else
    {
      progress=0;
    }


    oled.display();
    delay(50);
}
