//定义位选引脚
int seg_1=5;
int seg_2=18;
int seg_3=19;
int seg_4=21;
//定义位选数组
int seg_array[4]={seg_1,seg_2,seg_3,seg_4};
//定义段选引脚
int a=32;
int b=25;
int c=27;
int d=12;
int e=13;
int f=33;
int g=26;
int dp=14;
//定义段选数组
int led_array[8]={a,b,c,d,e,f,g,dp};
//定义共阴极数码管各个数字的逻辑电平
int logic_array[10][8]=
{ 
  {1,1,1,1,1,1,0,0},//0
  {0,1,1,0,0,0,0,0},//1
  {1,1,0,1,1,0,1,0},//2
  {1,1,1,1,0,0,1,0},//3
  {0,1,1,0,0,1,1,0},//4
  {1,0,1,1,0,1,1,0},//5
  {1,0,1,1,1,1,1,0},//6
  {1,1,1,0,0,0,0,0},//7
  {1,1,1,1,1,1,1,0},//8
  {1,1,1,1,0,1,1,0},//9                                                
};
void setup() 
{
    //初始化位选引脚
  for(int i=0;i<4;i++)
  {
    pinMode(seg_array[i],OUTPUT);
  }
  for(int i=0;i<4;i++)
  {
    digitalWrite(seg_array[i],HIGH);
  }
  //初始化段选引脚
  for(int i=0;i<8;i++)
  {
    pinMode(led_array[i],OUTPUT);
    digitalWrite(led_array[i],LOW);
  }

}
void display(int num,int order)
{
    //初始化位选引脚
  for(int i=0;i<4;i++)
  {
    pinMode(seg_array[i],OUTPUT);
  }
  for(int i=0;i<4;i++)
  {
    digitalWrite(seg_array[i],HIGH);
  }
  //初始化段选引脚
  for(int i=0;i<8;i++)
  {
    pinMode(led_array[i],OUTPUT);
    digitalWrite(led_array[i],LOW);
  }
    digitalWrite(seg_array[order],LOW);
    for(int i=0;i<8;i++)
    {
    digitalWrite(led_array[i],logic_array[num][i]);
    }
}
int num_array[4];
void display4(int num)
{
  if(num<=9999)
  { 
    for(int i=3;i>=0;i--)
    {
      num_array[i]=num%10;
      num=num/10;
    }  
   for(int i=0;i<4;i++)
    {
      display(num_array[i],i);
      delay(5);
    } 
  }
}
void loop() 
{
    /*display(1,0);
    delay(1000);
    display(2,1);
    delay(1000);
    display(3,2);
    delay(1000);    
    display(4,3);
    delay(1000);
    display(5,0);
    delay(1000);
    display(6,1);
    delay(1000);
    display(7,2);
    delay(1000);
    display(8,3);
    delay(1000);*/
   /* for(int j=0;j<4;j++)
    {
        for(int i=0;i<10;i++)
        {
            display(i,j);
            delay(100);
        }
    }*/
    
  display4(6666);
}
