#include <Arduino.h>
char key;
int row_pins[4] = {13, 12, 14, 27}; // 定义行引脚
int col_pins[4] = {26, 25, 33, 32}; // 定义列引脚

void setup() 
{
  Serial.begin(9600); // 初始化串口通信
  for (int i = 0; i < 4; i++) 
  {
    pinMode(row_pins[i], INPUT_PULLUP); // 设置行引脚为输入模式
    pinMode(col_pins[i], OUTPUT); // 设置列引脚为输出模式
    digitalWrite(col_pins[i], HIGH); // 初始时将列引脚拉高
  }
}

char readKey() 
{
  char key[4][4] =
  {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
  };
for(int j=0;j<4;j++)
{
  digitalWrite(col_pins[j], LOW); // 将列引脚拉低
  for(int i=0;i<4;i++)
  {
    if(digitalRead(row_pins[i])==LOW)
    {
      return key[i][j]; // 返回按键值
      digitalWrite(col_pins[j], HIGH); // 将列引脚拉高
    }
  }
  digitalWrite(col_pins[j], HIGH); // 将列引脚拉高
}
  return NULL;

}


void loop() 
{
  key = readKey(); // 读取按键
  if(key)
  {
    Serial.print("Key: ");
    Serial.println(key); // 输出按键值
  }
  delay(100); // 延时100毫秒
}

