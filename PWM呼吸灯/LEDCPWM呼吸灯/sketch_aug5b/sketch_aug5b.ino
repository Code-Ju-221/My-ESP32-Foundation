
#define LED  12
#define CHANNEL 0
#define FREQ 2000
#define RESOLUTION 8



void setup() 
{
  //ledcSetup(CHANNEL, FREQ, RESOLUTION);//设置通道
  ledcAttach(LED, FREQ, RESOLUTION);//设置引脚
}

void loop() 
{
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) //i<pow(2, RESOLUTION)
  {
    ledcWrite(LED, dutyCycle);//设置占空比
    delay(10);
  }
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) 
  {
    ledcWrite(LED, dutyCycle);//设置占空比
    delay(10);
  }

}
