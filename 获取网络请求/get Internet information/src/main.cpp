#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

//定义WIFI ID与PIN
const char*ssid="ChinaNet-b2Ti";
const char*password="mwi9m54v";
String url="https://apis.juhe.cn/simpleWeather/query";//指定请求的URL
String city="富平";
String key="4c1fb5d1eaa0b816a1b456e146fb4a5e";

void setup() 
{
  Serial.begin(9600);
  WiFi.begin(ssid,password);
  Serial.println("Connecting to WiFi");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("Connecting to WiFi");
    delay(1000);
  }
  Serial.println("Connected to WiFi");
  Serial.println("WIFI IP地址:");
  Serial.println(WiFi.localIP());
  HTTPClient http;//创建HTTP对象
  http.begin("https://apis.juhe.cn/simpleWeather/query");//指定请求的URL
  http.begin(url+"?city="+city+"&key="+key);//指定访问的URL
  int httpResponseCode = http.GET();//接收HTTP响应GET请求
  Serial.printf("HTTP状态码:%d\n",httpResponseCode); 
  String response = http.getString();//获取HTTP响应内容
  Serial.println(response);
  http.end();//结束HTTP请求
  //创建JSON对象
  DynamicJsonDocument doc(1024);
  //解析JSON响应内容
  deserializeJson(doc,response);
  //获取JSON对象中的数据
  unsigned int temperature = doc["result"]["realtime"]["temperature"].as<unsigned int>();
  String info=doc["result"]["realtime"]["info"].as<String>();
  int aqi=doc["result"]["realtime"]["aqi"].as<int>();
  Serial.printf("温度：%d℃\n,天气状况:%s\n,空气质量指数：%d\n",temperature,info,aqi);
  Serial.println("数据获取完毕");
  
} 


void loop() 
{
  

}