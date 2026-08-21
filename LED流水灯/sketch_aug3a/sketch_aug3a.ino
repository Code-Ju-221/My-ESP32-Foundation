int pin_list[5]={13,12,14,27,26};
int num=sizeof(pin_list)/sizeof(pin_list[0]);

void setup() 
{
  for(int i=0;i<5;i++)
  {
    pinMode(pin_list[i],OUTPUT);
  }
  

}

void loop() 
{
  /*
  for(int i=0;i<num;i++)
  {
    digitalWrite(pin_list[i],HIGH);
    delay(50);
  }
 
  for(int i=num;i>=0;i--)
  {
    digitalWrite(pin_list[i],LOW);
    delay(50);
  }
 */
  for(int i=0;i<num;i++)
  {
    digitalWrite(pin_list[i],HIGH);
    if(i>0)
    {
      digitalWrite(pin_list[i-1],LOW);
    }
    else
    digitalWrite(pin_list[num-1],LOW);
    delay(250);
  }
    


}
