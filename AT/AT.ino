
#include <SoftwareSerial.h>
// Pin10为RX，接HC05的TXD
// Pin11为TX，接HC05的RXD
SoftwareSerial BT(10, 11);
char val;
void setup()
{
  // 设置波特率为 38400
  Serial.begin(38400);
  pinMode(13, OUTPUT);
}


void loop()
{
  if (Serial.available()>0)
  { 
    val = Serial.read();
    BT.print(val);
  }
  if (BT.available())
  { 
    val = BT.read();
    Serial.println(val);
  }
  while(Serial.available())
  {
    char c=Serial.read();
      if(c=='1')
      {
        Serial.println("BT is ready!");
        // 返回到手机调试程序上
        Serial.write("Serial--13--high");
        digitalWrite(13, HIGH);
      }
     if(c=='2')
     {
       Serial.write("Serial--13--low");
       digitalWrite(13, LOW);
     }
  }
    
}
