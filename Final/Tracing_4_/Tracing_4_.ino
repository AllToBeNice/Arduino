//四路循迹
#include <Servo.h>  //（暂定，超声循迹用）舵机

#define Stop      0
#define Forward   1
#define Backward  2
#define TurnLeft  3
#define TurnRight 4

int LeftMotor1 = 16;  //左侧，前，电机
int LeftMotor2 = 17;  //左侧，后，电机
int RightMotor1 = 18; //右侧，前，电机
int RightMotor2 = 19; //右侧，后，电机

//从车头方向的最右边开始排序 (传感器)
int Trac1 = 10; //1号
int Trac2 = 11; //2号（黑线）
int Trac3 = 12; //3号（黑线）
int Trac4 = 13; //4号

int data[4];


Servo MyServo;  //（暂定，超声循迹用）舵机

//（暂定）HC-SR04接口
int InputPin = 7; // 定义超声波信号 接收 接口
int OutputPin = 8; // 定义超声波信号 发出 接口

//串口初始化
void setup() {
  Serial.begin(9600);

  //（暂定）舵机引脚初始化
  MyServo.attach(9);

  //测速引脚初始化
  pinMode(LeftMotor1, OUTPUT);
  pinMode(LeftMotor2, OUTPUT);
  pinMode(RightMotor1, OUTPUT);
  pinMode(RightMotor2, OUTPUT);


  //红外寻迹模块TCRT5000引脚初始化
  pinMode(Trac1, INPUT);
  pinMode(Trac2, INPUT);
  pinMode(Trac3, INPUT);
  pinMode(Trac4, INPUT);
}

void loop()
{

  Tracing(); //循迹

}

void MotorRun(int cmd) {
  switch (cmd)
  {
    //判断cmd的状态：如果cmd==Forward，输出“Forward/r/n”的状态，为LEFTMotor1设置为高电平，为leftMotor2设置为低电平，为RightMotor1设置为高电平，为RightMotor2设置为低电平
    case Forward:
      //调试用（输出状态）
      Serial.println("Forward");
      //前轮驱动
      digitalWrite(LeftMotor1, HIGH);
      digitalWrite(LeftMotor2, LOW);
      delayMicroseconds(450);          //占空比调速
      digitalWrite(RightMotor1, HIGH);
      digitalWrite(RightMotor2, LOW);
      delayMicroseconds(550);
      break;
    //完成以上一系列函数后结束这个函数
    case Backward:
      //调试用（输出状态）
      Serial.println("Backward");
      //后轮驱动
      digitalWrite(LeftMotor1, LOW);
      digitalWrite(LeftMotor2, HIGH);
      delayMicroseconds(450);
      digitalWrite(RightMotor1, LOW);
      digitalWrite(RightMotor2, HIGH);
      delayMicroseconds(550);
      break;
    case TurnLeft:
      //调试用（输出状态）
      Serial.println("TurnLeft");
      //左转
      digitalWrite(LeftMotor1, HIGH);
      digitalWrite(LeftMotor2, LOW);
      delayMicroseconds(450);
      digitalWrite(RightMotor1, LOW);
      digitalWrite(RightMotor2, HIGH);
      delayMicroseconds(550);
      break;
    case TurnRight:
      //调试用（输出状态）
      Serial.println("TurnRight");
      //右转
      digitalWrite(LeftMotor1, LOW);
      digitalWrite(LeftMotor2, HIGH);
      delayMicroseconds(450);
      digitalWrite(RightMotor1, HIGH);
      digitalWrite(RightMotor2, LOW);
      delayMicroseconds(550);
      break;
    default:
      //调试用（输出状态）
      Serial.println("Stop");
      //如果以上情况都不是，停止，所有电机输出为低电平
      digitalWrite(LeftMotor1, LOW);
      digitalWrite(LeftMotor2, LOW);
      delayMicroseconds(450);
      digitalWrite(RightMotor1, LOW);
      digitalWrite(RightMotor2, LOW);
      delayMicroseconds(550);
  }
}





//定义循迹函数Tracing。调用MotorRun函数
void Tracing()
{
  do {
    data[0] = digitalRead(10);
    data[1] = digitalRead(11);
    data[2] = digitalRead(12);
    data[3] = digitalRead(13);

    //左右都没有检测到黑线，前进
    if (!data[0] && !data[1] && !data[2] && !data[3])
    {
      MotorRun(Forward);
    }

    //右边检测到黑线，右转
    if (data[0] || data[1])
    {
      MotorRun(TurnRight);
    }

    //左边检测到黑线，左转
    if (data[2] || data[3])
    {
      MotorRun(TurnLeft);
    }
    //测试用（输出信号）
    Serial.print(data[0]);
    Serial.print("---");
    Serial.print(data[1]);
    Serial.print("---");
    Serial.print(data[2]);
    Serial.print("---");
    Serial.println(data[3]);
  }
  //左右都检测到黑线，停止
  while (data[0] && data[3]);
  MotorRun(Stop);
  delay(1000);
}
