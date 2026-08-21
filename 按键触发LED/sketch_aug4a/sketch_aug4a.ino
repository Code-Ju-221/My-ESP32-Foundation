int pin_LED = 2; 
int pin_button = 14;
int LED_logic=0;
bool state = false;


void setup() 
{
    pinMode(pin_LED, OUTPUT);
    pinMode(pin_button, INPUT_PULLDOWN);
}

void loop() 
{
    if (digitalRead(pin_button) ==1) 
    delay(10);
    if (digitalRead(pin_button) ==1&&!state) 
    {
        LED_logic = !LED_logic;
        digitalWrite(pin_LED, LED_logic);
        state = true;
    }
        else if (digitalRead(pin_button) ==0)
        {
          state=false;
        }
}
