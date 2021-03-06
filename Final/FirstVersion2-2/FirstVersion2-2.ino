//First Version
//-------------------蜂鸣器-----------------------
//蜂鸣器口，pin = 8
//-------------------L298N------------------------
//左侧，前，电机,pin = 2
//左侧，后，电机,pin = 3
//右侧，前，电机,pin = 4
//右侧，后，电机,pin = 5
//-------------定义电机调速引脚--------------------
//左侧，pin = 5;
//右侧，pin = 6;
//------传感器（从车头方向的最右边开始排序）--------
//1号，pin = 10
//2号（黑线），pin = 11
//3号（黑线），pin = 12
//4号，pin = 13
//------------------------------------------------
//潮鸣
//音符唱名记法
#define Do  262
#define Re  294
#define Mi  330
#define Fa  350
#define Sol 392
#define La  441
#define Si  495
#define Doo 882

//音名记法
#define C  262
#define D  294
#define E  330
#define F  350
#define G  392
#define A  441
#define B  495
#define CC 525
#define DD 589
#define EE 661
#define AA 882


//音符唱名记法
#define Do  262
#define Re  294
#define Mi  330
#define Fa  350
#define Sol 393
#define La  441
#define Si  495
#define Doo 882

//音名记法
#define C  262
#define D  294
#define E  330
#define F  350
#define G  392
#define A  441
#define B  495
#define CC 525
#define DD 589
#define EE 661
#define AA 882
#define O  -1 //听不到的声音

//四路循迹
#include <Servo.h>  //（暂定，超声循迹用）舵机

#define Stop      0
#define Forward   1
#define Backward  2
#define TurnLeft  3
#define TurnRight 4
//------------------------------------------------
int buzzer = 8; //蜂鸣器，pin = 8

//旋律
int scale[] = {G, A, EE, A, G, A, G, A, EE, A, G,
               A, EE, A, G, A, E,
               G, D, E, G, A, B,
               A, EE, A, G, A, G,
               A, EE, B, CC, B, CC, B, A, E,
               D, E, G, A, B, A, EE, A, G, A,
               G, A, EE, A, G, A, EE, A, G, A,
               E, G, D, E, G, A, B, A, EE, A, G, A,
               G, A, EE, B, CC, B, CC, DD, EE, AA
              };

//音符时值
float duration[] = {2, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 3, 1,
                    3, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 7, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 6,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 7,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
                    1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 4
                   };
int len = 0; //用于统计音符个数

int LeftMotor1 = 16;  //左侧，前，电机
int LeftMotor2 = 17;  //左侧，后，电机
int RightMotor1 = 18; //右侧，前，电机
int RightMotor2 = 19; //右侧，后，电机

//从车头方向的最右边开始排序 (传感器)
int Trac1 = 10; //1号
int Trac2 = 11; //2号（黑线）
int Trac3 = 12; //3号（黑线）
int Trac4 = 13; //4号

int data[4];    //红外循迹数据
Servo MyServo;  //（暂定，超声循迹用）舵机

//（暂定）HC-SR04接口
int InputPin = 7; // 定义超声波信号 接收 接口
int OutputPin = 8; // 定义超声波信号 发出 接口


void setup() {
  // put your setup code here, to run once:
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

  pinMode(buzzer, OUTPUT);
  len = sizeof(scale) / sizeof(scale[0]); //计算音乐长度

}

void loop() {
  // put your main code here, to run repeatedly:

  Tracing();//循迹
  MotorRun(Forward);//前进
  Ultrasonic();//超声循迹

  Tracing();//循迹，其作用是调整姿态，直至全部检测到黑线
  MotorRun(Forward);//前进
  Buzzer();//发声
  Tracing();//循迹，其作用是调整姿态，直至全部检测到黑线
  MotorRun(Forward);//前进
  Bluetooth();//执行蓝牙手控,内循环！！！

}



//定义驱动函数MotorRun
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


//定义超声循迹函数 Ultrasonic
void Ultrasonic() {
  do {
    data[0] = digitalRead(10);
    data[1] = digitalRead(11);
    data[2] = digitalRead(12);
    data[3] = digitalRead(13);

  }
  while (data[0] && data[3]);
  MotorRun(Stop);
  delay(1000);

}


//定义发声函数Buzzer
void Buzzer() {
  for (int i = 0; i < len; i++) {
    tone(buzzer, scale[i]);
    delay(250 * duration[i]);
    noTone(buzzer);
    delay(100);
  }
  delay(1000);
}


//定义蓝牙手控函数Bluetooth
void Bluetooth() {

}
