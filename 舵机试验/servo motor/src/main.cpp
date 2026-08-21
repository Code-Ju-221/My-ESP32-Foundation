 #include <Arduino.h>
#define FREQ         50//HZ
#define CHANNAL      0/*高速PWM通道（0-7），低速PWM通道（8-15）*/
#define RESOLUTION   8//8位分辨率
#define MotorPin     13


void setup() 
{   
    ledcSetup(CHANNAL, FREQ, RESOLUTION);//建立LEDC通道
    ledcAttachPin(13, 0);//关联LEDC与GPIO通道
}


int PWM(int degree)
{
    int min_width=0.5/20 *pow(2,RESOLUTION);
    int max_width=2.5/20 *pow(2,RESOLUTION);
    return (max_width-min_width)*degree/180+min_width;

    /*ledcWrite(CHANNAL,(max_width-min_width)*degree/180+min_width);
    delay(500);
    ledcWrite(CHANNAL, max_width);
    delay(500);*/
}



void loop() 
{
    /*int min_width=0.5/20 *pow(2,RESOLUTION);
    int max_width=2.5/20 *pow(2,RESOLUTION);
    ledcWrite(CHANNAL,(max_width-min_width)*50/180+min_width);
    delay(500);
    ledcWrite(CHANNAL, max_width);
    delay(500);*/
    for(int i=0;i<180;i++)
    {
        ledcWrite(CHANNAL,PWM(i));
        delay(50);
    }
    for(int i=180;i>=0;i--)
    {
        ledcWrite(CHANNAL,PWM(i));
        delay(50);
    }


}


