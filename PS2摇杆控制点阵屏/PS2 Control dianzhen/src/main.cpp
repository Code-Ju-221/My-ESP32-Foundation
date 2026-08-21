#include <Arduino.h>

#define PS2_X 15
#define PS_Y  35
int hex[8]={0x00,0x66,0xFF,0xFF,0xFF,0x7E,0x3C,0x18};

int row_array[8] = {13, 25, 2, 27, 23, 4,22, 18}; // 8位点阵屏的行数组
int col_array[8] = {26, 21, 19, 12, 5, 14, 33, 32}; // 8位点阵屏的列数组

int led_pos[2]={1,2};
int x_value;
int y_value;

void setup() 
{
  pinMode(PS2_X, INPUT); // 设置PS2 X轴引脚为输入模式
  pinMode(PS_Y, INPUT); // 设置PS2 Y轴引脚为输入模式
  
  
  
  for (int i = 0; i < 8; i++) 
  {
    pinMode(row_array[i], OUTPUT); // 设置行数组的引脚为输出模式
    pinMode(col_array[i], OUTPUT); // 设置列数组的引脚为输出模式
  }
  for (int i = 0; i < 8; i++) 
  {
    digitalWrite(row_array[i], HIGH); // 将行数组的引脚拉高
    digitalWrite(col_array[i], LOW); // 将列数组的引脚拉低
  }

  
}





void loop() 
{

  digitalWrite(row_array[led_pos[0]], HIGH); // 将行数组的引脚拉低
  digitalWrite(col_array[led_pos[1]], LOW);
  x_value = analogRead(PS2_X); // 读取PS2 X轴的模拟值
  y_value = analogRead(PS_Y); // 读取PS2 Y轴的模拟值
  
  if(x_value>4055/2 +300 && led_pos[0]<7)
  {
    led_pos[0]+=1;;
  }
  else if(x_value<4055/2 -300 && led_pos[0]>0)
  {
    led_pos[0]-=1;
  }
    if(y_value>4055/2 +300 && led_pos[1] >0)
  {
    led_pos[1]-=1;
  }
  else if(y_value<4055/2 -300 && led_pos[1]<7)
  {
    led_pos[1]+=1;
  }
  digitalWrite(row_array[led_pos[0]], LOW); // 将行数组的引脚拉低
  digitalWrite(col_array[led_pos[1]], HIGH); // 将列数组的引脚拉高
  delay(50); // 延时100毫秒
}

