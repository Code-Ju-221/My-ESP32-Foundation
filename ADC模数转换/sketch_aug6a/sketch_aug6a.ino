/*#define POT 26
int POT_VALUE;

void setup() 
{
  Serial.begin(9600);
  pinMode(POT, INPUT);
}

void loop() 
{
  POT_VALUE = analogRead(POT);
  Serial.println(POT_VALUE);
  delay(100);
}
*/

/*#define POT 26
#define LED 13
int POT_VALUE;
int LED_VALUE;
void setup()
{
  pinMode(POT,INPUT);
  pinMode(LED, OUTPUT);
}
void loop()
{
  POT_VALUE=analogRead(POT);
  LED_VALUE=(POT_VALUE)/16;
  digitalWrite(LED,LED_VALUE);
  delay(100);
}
*/

#define CHANNEL    0//自动分配通道，不需要这个宏定义
#define FREQ       1000
#define RESOLUTION 12
#define LED        13
#define POT        26
int pot_value;
void setup()
{
  analogReadResolution(RESOLUTION);
  analogSetAttenuation(ADC_11db);
  //ledcSetup(CHANNEL, FREQ, RESOLUTION);
  ledcAttach(LED, FREQ, RESOLUTION);
}
void loop()
{
  pot_value = analogRead(POT);
  ledcWrite(LED, pot_value);
  delay(100);
}


