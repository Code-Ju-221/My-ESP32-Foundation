int pin_a=4;
int pin_b=5;
int pin_c=19;
int pin_d=21;
int pin_e=22;
int pin_f=2;
int pin_g=15;
int pin_dp=18;
int pin_list[8]={pin_a,pin_b,pin_c,pin_d,pin_e,pin_f,pin_g,pin_dp};
int pin_num_list[][8]={ 
  {0,0,0,0,0,0,1,1},//0
  {1,0,0,1,1,1,1,1},//1
  {0,0,1,0,0,1,0,1},//2
  {0,0,0,0,1,1,0,1},//3
  {1,0,0,1,1,0,0,1},//4
  {0,1,0,0,1,0,0,1},//5
  {0,1,0,0,0,0,0,1},//6
  {0,0,0,1,1,1,1,1},//7
  {0,0,0,0,0,0,0,1},//8
  {0,0,0,0,1,0,0,1},//9                                                
};

void display_num(int num)
{
  for(int i=0;i<8;i++)
  {
      digitalWrite(pin_list[i],pin_num_list[num][i]);
  }
}
void setup() 
{
  for(int i=0;i<8;i++)
  {
   pinMode(pin_list[i],OUTPUT); 
   digitalWrite(pin_list[i],HIGH);
  }
}
void loop() 
{
  for(int i=0;i<10;i++)
  {
    display_num(i);
    delay(1000);
  }
}
