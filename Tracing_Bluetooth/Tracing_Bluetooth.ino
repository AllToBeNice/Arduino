// CurieBLE - Version: Latest 


#include <Servo.h>

//定义五种运动状态
#define Stop      0
#define Forward   1
#define Backward  2
#define TurnLeft  3
#define TurnRight 4

//定义电机引脚
int LeftMotor1 = 4;
int LeftMotor2 = 5;
int RightMotor1 = 6;
int RightMotor2 = 7;

//定义电机调速引脚
int LeftPWM = 9;
int RightPWM = 3;

//定义红外循迹引脚
int Trac1 = 10; //从车头方向的最右边开始排序
int Trac2 = 11; 
int Trac3 = 12; 
int Trac4 = 13; 

//初始化
void setup() {
  Serial.begin(9600);  //设置串口通信
  
  //设置控制电机的引脚为输出状态
  pinMode(LeftMotor1, OUTPUT);//In1
  pinMode(LeftMotor2, OUTPUT);//In2
  pinMode(RightMotor1, OUTPUT);//In3
  pinMode(RightMotor2, OUTPUT);//In4

  pinMode(LeftPWM, OUTPUT);
  pinMode(RightPWM, OUTPUT);
  
  //定义循迹模块
  pinMode(Trac1, INPUT);
  pinMode(Trac2, INPUT);
  pinMode(Trac3, INPUT);
  pinMode(Trac4, INPUT);
}
 
void loop()
{
  Tracing();
}
void Tracing()
{
   int data[4];
  data[0] = digitalRead(Trac1);
  data[1] = digitalRead(Trac2);
  data[2] = digitalRead(Trac3);
  data[3] = digitalRead(Trac4);
 
  if(data[0] && data[1] && data[2] && data[3])  //左右都没有检测到黑线
  {
    motorRun(Forward, 255);
  }
 
  if(!data[0] || !data[1])  //右边检测到黑线
  {
    motorRun(TurnRight, 160);
  }
 
  if(!data[2] || !data[3])  //左边检测到黑线
  {
    motorRun(TurnLeft, 100);
  }
 
  if(!data[0] && !data[3])  //左右都检测到黑线是停止
  {
    motorRun(Stop, 40); 
  }

 //测试用（输出信号）
  Serial.print(data[0]);
  Serial.print("---");
  Serial.print(data[1]);
  Serial.print("---");
  Serial.print(data[2]);
  Serial.print("---");
  Serial.print(data[3]);
}

//蓝牙部分
void loop2() {
  char data='1';
  int temp=0;
   if(Serial.available()>0)
  {
    char cmd = Serial.read();//读取蓝牙模块发送到串口的数据
    switch(cmd){
      case '1':
         temp=1;
         break;
      case '2':
         temp=2;
         break;
       case '3':
         temp=3;
         break;
      case '4':
         temp=4;
         break;
      case '0':
         temp=0;
         break;
            
    }
    motorRun(temp,100);
 
  }  
}

//运动控制函数
void motorRun(int cmd,int value)
{
  analogWrite(LeftPWM, value);
  analogWrite(RightPWM, value);
  switch(cmd){
    case Forward :
      digitalWrite(LeftMotor1, LOW);
      digitalWrite(LeftMotor2, HIGH);
      digitalWrite(RightMotor1, LOW);
      digitalWrite(RightMotor2, HIGH);
      break;
     case Backward:
      digitalWrite(LeftMotor1, HIGH);
      digitalWrite(LeftMotor2, LOW);
      digitalWrite(RightMotor1, HIGH);
      digitalWrite(RightMotor2, LOW);
      break;
     case TurnLeft:
      digitalWrite(LeftMotor1, HIGH);
      digitalWrite(LeftMotor2, LOW);
      digitalWrite(RightMotor1, LOW);
      digitalWrite(RightMotor2, HIGH);
      break;
     case TurnRight:
      digitalWrite(LeftMotor1, LOW);
      digitalWrite(LeftMotor2, HIGH);
      digitalWrite(RightMotor1, HIGH);
      digitalWrite(RightMotor2, LOW);
      break;
     default:
      digitalWrite(LeftMotor1, LOW);
      digitalWrite(LeftMotor2, LOW);
      digitalWrite(RightMotor1, LOW);
      digitalWrite(RightMotor2, LOW);
  }
}
 
