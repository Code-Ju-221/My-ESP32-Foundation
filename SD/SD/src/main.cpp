#include <Arduino.h>
#include<SD.h>


File myFile;
void listFiles(const char* path);
  void setup() 
{
  Serial.begin(9600);
  // Initialize SD card. Use default pins; adjust if your board needs a CS pin argument.
  if (!SD.begin())
  {
    Serial.println("SD Card Failed to Initialize");
    return;
  }
  else
    Serial.println("SD Card Initialized Successfully");
  myFile = SD.open("/test.txt", FILE_WRITE);
  if(myFile)
  {
    Serial.println("File Opened Successfully");
    myFile.println("Hello World");
    myFile.close();
    Serial.println("File Closed Successfully");

  }
  else
  {
    Serial.println("File Open Failed");
  }
  delay(1000);
  myFile = SD.open("/test.txt", FILE_READ);
  while(myFile.available())
  {
    Serial.write(myFile.read());
  }
  myFile.close();
  Serial.println("\nFile Read Successfully");
  delay(1000);

  myFile = SD.open("/test.txt", FILE_APPEND);
  myFile.println("Hello Again");
  myFile.close();
  Serial.println("File Appended Successfully");
  delay(1000);
  myFile = SD.open("/test.txt", FILE_READ);
  while(myFile.available())
  {
    Serial.write(myFile.read());
  }
  myFile.close();
  Serial.println("\nFile Read Successfully");
  delay(1000);
  listFiles("/");
  SD.remove("/test.txt");
  if(!SD.exists("/test.txt"))
  {
    Serial.println("File Removed Successfully");
  }
  else
  {
    Serial.println("File Removal Failed");
  }

}

void listFiles( const char*path)
{
    Serial.println("文件列表：");
    File root = SD.open(path);
    File file = root.openNextFile();
    while (file)
    {
    if (file.isDirectory())
    {
        Serial.print("目录：");
    }
    else
    {
        Serial.print("文件：");
    }
    Serial.println(file.name());
    file = root.openNextFile();
    }
    root.close();
    file.close();
}


void loop() 
{

}
  


