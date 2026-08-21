#include <Arduino.h>
#include <U8g2lib.h>
#define BUTTON_UP    12
#define BUTTON_DOWN  14
U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, 18, 13, 4, 2, 15); // 时钟线, 数据线, CS, DC, RESET
void display_menu(int index);
char*menu[4]={"Item1", "Item2", "Item3", "Item4"};
int order=0;
void setup() 
{
  //初始化OLED
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x12_tr); 
  //配置按键输入
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
}

void loop() 
{
  if(digitalRead(BUTTON_UP)==LOW)
  {
    order=(order-1+4)%4;
    delay(200); 
  }
  if(digitalRead(BUTTON_DOWN)==LOW)
  {
    order=(order+1)%4;
    delay(200);
  }

   display_menu(order);
}









void display_menu(int index)
{
  u8g2.firstPage();
  do
  {
    u8g2.drawStr(0, 12, "Menu");
    u8g2.drawLine(0, 14, 128, 14);
    for(int i=0;i<4;i++)
    {
      if(i==index)
      {
        u8g2.drawStr(5, (i+2)*12, ">");
        u8g2.drawStr(15, (i+2)*12, menu[i]);
      }
       else
       {
          u8g2.drawStr(5, (i+2)*12, menu[i]);//字高是12
       } 
      
        
      
    }
  }
  while (u8g2.nextPage());





}