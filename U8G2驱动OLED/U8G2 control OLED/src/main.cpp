#include <Arduino.h>
#include <U8g2lib.h>

//构造对象
//U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0,18,13,4,2,15);
U8G2_SSD1306_128X64_NONAME_2_4W_SW_SPI u8g2(U8G2_R0,18,13,4,2,15);

int progress = 0;



void setup() 
{
  u8g2.begin();
  //u8g2.enableUTF8Print(); //启用UTF8支持,即中文
  //u8g2.setFont(u8g2_font_wqy12_t_chinese2); //设置字体
}

void loop() 
{
  /*u8g2.clearBuffer();
  u8g2.setCursor(0, 20);
  u8g2.print("Hello World!"); //打印英文
  u8g2.setCursor(0, 40);
  u8g2.print("你好,ESP32"); //打印中文
  u8g2.sendBuffer(); //发送缓冲区内容到显示屏*/
  u8g2.firstPage();
  do 
  {
    u8g2.drawFrame(0, 10, 128, 20);//显示边框
    u8g2.drawBox(5, 15, progress, 10);//显示进度条
  } 
  while (u8g2.nextPage());
  if(progress < 118)
  {
    progress++;
  }
  else
  {
    progress = 0;
  }
}

