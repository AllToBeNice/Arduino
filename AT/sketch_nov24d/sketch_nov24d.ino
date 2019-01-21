#include <SoftwareSerial.h> 

//电机逻辑
int pinI1 = 6; //电机右
int pinI2 = 5;
int pinI3 = 4; 
int pinI4 = 3;
//电机PWM
int ea=7;//右
int eb=2;//左

char control;

void setup()
{ 
    pinMode(pinI1,OUTPUT);//定义电机IO口为输出
    pinMode(pinI2,OUTPUT);  
    pinMode(pinI3,OUTPUT);
    pinMode(pinI4,OUTPUT); 
    pinMode(ea,OUTPUT);
    pinMode(eb,OUTPUT);
    
    

    Serial.begin(9600);//开启蓝牙串口
    Serial.println("BT is ready!");


}

void loop()
{ 
    if(Serial.available())
    {
      control=Serial.read();
      if(control=='W')
      {
          Go();
      }
      if(control=='A')
      {
          Left();
      }
      if(control=='S')
      {
          Back();
      }
      if(control=='D')
      {
          Right();
      }
      if(control=='P')
      {
          Stop();
      }
    }
}


void Go()//前行
{
    digitalWrite(pinI2,HIGH);
    digitalWrite(pinI1,LOW); 
    analogWrite(ea,70); 
    digitalWrite(pinI4,LOW);
    digitalWrite(pinI3,HIGH);
    analogWrite(eb,70); 
}

void Back()//后退
{
    digitalWrite(pinI2,LOW);
    digitalWrite(pinI1,HIGH); 
    analogWrite(ea,70); 
    digitalWrite(pinI4,HIGH);
    digitalWrite(pinI3,LOW);
    analogWrite(eb,70); 
}

void Right()//右转
{
    digitalWrite(pinI1,HIGH);
    digitalWrite(pinI2,LOW); 
    analogWrite(eb,70); 
    digitalWrite(pinI3,HIGH);
    digitalWrite(pinI4,LOW);
    analogWrite(ea,70); 
}

void Left()//左转
{
    digitalWrite(pinI1,LOW);
    digitalWrite(pinI2,HIGH); 
    analogWrite(eb,70); 
    digitalWrite(pinI3,LOW);
    digitalWrite(pinI4,HIGH);
    analogWrite(ea,70); 
}

void Stop()//停止
{
    digitalWrite(pinI1,HIGH);
    digitalWrite(pinI2,HIGH);
    digitalWrite(pinI3,HIGH);
    digitalWrite(pinI4,HIGH);
}
