#include <Arduino.h>

int row_array[8] = {13, 25, 2, 27, 23, 4,22, 18}; // 8位点阵屏的行数组
int col_array[8] = {26, 21, 19, 12, 5, 14, 33, 32}; // 8位点阵屏的列数组


void setup() 
{
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
  for (int i = 0; i < 8; i++) 
  {
    digitalWrite(row_array[i],LOW);
    for (int j = 0; j < 8; j++) 
    {
      digitalWrite(col_array[j], HIGH);
      delay(100);
      digitalWrite(col_array[j], LOW);
    }
    digitalWrite(row_array[i], HIGH);
  }
}

