
//蓝牙模块RXD----2


#include <SoftwareSerial.h>
int i;
SoftwareSerial softSerial(2, 13);//设置蓝牙接收引脚为2




void loop() {
  if (softSerial.available() > 0)
  {
    i = softSerial.read(); //接收蓝牙传来的数据
    Serial.println(i);

  }

}
