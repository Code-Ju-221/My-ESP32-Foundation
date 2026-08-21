#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


char key;
const char password[] = "1234"; // 定义密码
char entered_password[5] = {0}; // 定义已输入的密码（多一位存放终止符）
int row_pins[4] = {13, 12, 14, 27}; // 定义行引脚
int col_pins[4] = {26, 25, 33, 32}; // 定义列引脚
LiquidCrystal_I2C lcd(0x27, 16, 2); // 配置LCD对象
void setup() 
{
  
  for (int i = 0; i < 4; i++) 
  {
    pinMode(row_pins[i], INPUT_PULLUP); // 设置行引脚为输入模式
    pinMode(col_pins[i], OUTPUT); // 设置列引脚为输出模式
    digitalWrite(col_pins[i], HIGH); // 初始时将列引脚拉高
  }
  lcd.init(); // 初始化LCD
  lcd.backlight(); // 启动背光
  lcd.setCursor(0, 0); // 设置光标位置
  lcd.print("Enter Password:"); // 显示提示信息
  
}
void check(char key)
{
  if(key)
  {
    if(key=='#')
    {
      if(strcmp(entered_password, password)==0)
      {
        lcd.clear(); // 清屏
        lcd.print("Access Granted!"); // 显示成功信息
      }
      else
      {

        lcd.clear(); // 清屏
        lcd.print("Access Denied!"); // 显示失败信息
      }
      delay(2000); // 延时2秒
      lcd.clear(); // 清屏
      lcd.print("Enter Password:"); // 显示提示信息
      memset(entered_password, 0, sizeof(entered_password)); // 清空已输入的密码
    }
    else
    {
      if(strlen(entered_password)<4)
      {
        lcd.setCursor(strlen(entered_password), 1);
        lcd.print('*'); // 显示按键值
        entered_password[strlen(entered_password)] = key; // 将按键值添加到已输入的密码中
}
    }


  }

delay(500); // 延时500毫秒

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
      char k = key[i][j]; // 返回按键值
      digitalWrite(col_pins[j], HIGH); // 将列引脚拉高
      return k;
    }
  }     
  digitalWrite(col_pins[j], HIGH); // 将列引脚拉高
}
  return '\0';

}
void loop() 
{
  key = readKey(); // 读取按键
  check(key);
  
}
