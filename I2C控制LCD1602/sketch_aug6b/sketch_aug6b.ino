#include"LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display
    


void setup() 
{
    lcd.init();
    lcd.backlight();
    lcd.print("Hello, World!");

}

void loop() 
{
  

}
