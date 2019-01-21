//----------------------宏定义---------------------------------
//引入 DHT 库文件(温湿度传感器)
#include <DHT.h>
#define DHTTYPE DHT11
#define DHT11PIN A0            //定义数据输入引脚为A0
DHT dht(DHT11PIN, DHTTYPE);
//--------------------音符表示---------------------------------
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
#define Do_h 523
#define Re_h 587
#define Mi_h 659
#define Fa_h 698
#define Sol_h 784
#define La_h 880
#define Si_h 988

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

//天空之城
#define NOTE_D0 -1
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278

#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112

//这部分用英文对应了拍子
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
//-----------------------------------------------------------------------




//------------音符&时值（顺序：潮鸣、天空之城、生日快乐、摩斯电码）-------------
//-------------------------------潮鸣-------------------------------------
//旋律
int scale1[] = {
  G, A, EE, A, G, A, G, A, EE, A, G,
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
float duration1[] = {
  2, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 3, 1,
  3, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 7, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 6,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 7,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
  1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 4
};
//统计音符个数
int length1 = 0;
//------------------------------天空之城------------------------------------
//旋律
int tune2[] =
{
  NOTE_D0, NOTE_D0, NOTE_D0, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D3, NOTE_D3,
  NOTE_D6, NOTE_D5, NOTE_D6, NOTE_DH1, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D3, NOTE_D4, NOTE_D3, NOTE_D4, NOTE_DH1,
  NOTE_D3, NOTE_D3, NOTE_D0, NOTE_DH1, NOTE_DH1, NOTE_DH1, NOTE_D7, NOTE_D4, NOTE_D4, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D0, NOTE_D6, NOTE_D7,
  NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D3, NOTE_D3, NOTE_D6, NOTE_D5, NOTE_D6, NOTE_DH1,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_DH1, NOTE_D7, NOTE_D7, NOTE_DH1, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_DH3, NOTE_DH1, NOTE_DH1, NOTE_DH1,
  NOTE_DH1, NOTE_D7, NOTE_D6, NOTE_D6, NOTE_D7, NOTE_D5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_DH2, NOTE_DH3, NOTE_DH5,
  NOTE_DH2, NOTE_DH2, NOTE_DH2, NOTE_D5, NOTE_D5, NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3,
  NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D7, NOTE_DH2, NOTE_DH2, NOTE_DH1, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_DH4, NOTE_DH3, NOTE_DH2, NOTE_DH1,
  NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH6, NOTE_DH6, NOTE_DH5, NOTE_DH5, NOTE_DH3, NOTE_DH2, NOTE_DH1, NOTE_DH1, NOTE_D0, NOTE_DH1,
  NOTE_DH2, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_DH5, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH6, NOTE_DH6, NOTE_DH5, NOTE_DH5,
  NOTE_DH3, NOTE_DH2, NOTE_DH1, NOTE_DH1, NOTE_D0, NOTE_DH1, NOTE_DH2, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_D7, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D7
};
//时值
float duration2[] =
{
  1, 1, 1, 0.5, 0.5,     1 + 0.5, 0.5, 1, 1,     1, 1, 1, 0.5, 0.5,
  1 + 0.5, 0.5, 1, 1,     1, 1, 1, 1,          1 + 0.5, 0.5, 1, 1,
  1, 1, 0.5, 0.5, 0.5, 0.5,    1 + 0.5, 0.5, 1, 1,     1, 1, 1, 0.5, 0.5,
  1 + 0.5, 0.5, 1, 1,    1, 1, 1, 0.5, 0.5,     1 + 0.5, 0.5, 1, 1,
  1, 1, 1, 0.5, 0.5,    1, 0.5, 0.25, 0.25, 0.25, 0.5,    0.5, 0.5, 0.5, 0.25, 0.5, 1,
  0.5, 0.5, 0.5, 0.5, 1, 1,    1, 1, 1, 0.5, 0.5,    1 + 0.5, 0.5, 1, 1,
  1, 1, 1, 0.5, 0.5,    1.5, 0.5, 1, 1,    1, 1, 1, 1,
  0.5, 0.5, 1, 1, 0.5, 0.5,    1.5, 0.25, 0.5, 1,    1, 1, 1, 1,
  1, 1, 1, 1,    1, 1, 1, 1,    0.5, 0.5, 1, 1, 0.5, 0.5,
  1, 0.5, 0.5, 1, 1,    1, 1, 1, 1,    1, 1, 1, 1,
  0.5, 0.5, 1, 1, 0.5, 0.5,    1, 0.5, 0.25, 0.5, 1,    1, 1, 1, 0.5, 0.5
};
//统计音符个数
int length2;

//-----------------------------生日快乐----------------------------------------
//旋律
int scale3[] = {
  Sol, Sol, La, Sol, Do_h, Si,
  Sol, Sol, La, Sol, Re_h, Do_h,
  Sol, Sol, Sol_h, Mi_h, Do_h, Si, La,
  Fa_h, Fa_h, Mi_h, Do_h, Re_h, Do_h
};
//时值
float duration3[] =
{
  0.5, 0.5, 1, 1, 1, 1 + 1,
  0.5, 0.5, 1, 1, 1, 1 + 1,
  0.5, 0.5, 1, 1, 1, 1, 1,
  0.5, 0.5, 1, 1, 1, 1 + 1,
};
//统计音符个数
int length3;

/*/-------------------------------卡农-------------------------------------------
//旋律
int tune4[] =
{
  NOTE_DH3, NOTE_DH2,
  NOTE_DH1, NOTE_D7,
  NOTE_D6, NOTE_D5,
  NOTE_D6, NOTE_D7,
  NOTE_DH1, NOTE_D7,
  NOTE_D6, NOTE_D5,
  NOTE_D4, NOTE_D3,
  NOTE_D4, NOTE_D2,
  NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_D1, NOTE_DL7, NOTE_D5, NOTE_D2, NOTE_D3,
  NOTE_D1, NOTE_DH1, NOTE_D7, NOTE_D6, NOTE_D7, NOTE_DH3, NOTE_DH5, NOTE_DH6,
  NOTE_DH4, NOTE_DH3, NOTE_DH2, NOTE_DH4, NOTE_DH4, NOTE_DH3, NOTE_DH1, NOTE_D7,
  NOTE_D6, NOTE_D5, NOTE_D4, NOTE_D3, NOTE_D2, NOTE_D4, NOTE_D3, NOTE_D2,
  NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D2, NOTE_D5, NOTE_D4,
  NOTE_D3, NOTE_D6, NOTE_D5, NOTE_D4, NOTE_D5, NOTE_D4, NOTE_D3, NOTE_D2,
  NOTE_D1, NOTE_DL6, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D7, NOTE_D6, NOTE_D5,
  NOTE_D4, NOTE_D3, NOTE_D2, NOTE_D6, NOTE_D5, NOTE_D6, NOTE_D5, NOTE_D4,
  NOTE_D3, NOTE_DH3, NOTE_DH2,
  NOTE_DH1, NOTE_DH2,
  NOTE_DH1, NOTE_DH3, NOTE_DH2, NOTE_DH4,
  NOTE_DH5, NOTE_DH3, NOTE_DH4, NOTE_DH5, NOTE_DH3, NOTE_DH4, NOTE_DH5, NOTE_D5, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_DH4,
  NOTE_DH3, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D6, NOTE_D5, NOTE_D4, NOTE_D5, NOTE_D3, NOTE_D4, NOTE_D5,
  NOTE_D4, NOTE_D6, NOTE_D5, NOTE_D4, NOTE_D3, NOTE_D2, NOTE_D3, NOTE_D2, NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D6,
  NOTE_D4, NOTE_D6, NOTE_D5, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D5, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_DH4, NOTE_DH5,
  NOTE_DH3, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_DH2, NOTE_DH1, NOTE_DH2, NOTE_D7, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_DH2, NOTE_DH1, NOTE_D7,
  NOTE_DH1, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_D3, NOTE_D2, NOTE_D3, NOTE_DH1, NOTE_D7, NOTE_DH1,
  NOTE_D6, NOTE_DH1, NOTE_D7, NOTE_D6, NOTE_D5, NOTE_D4, NOTE_D5, NOTE_D4, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D6, NOTE_D7, NOTE_D1,
  NOTE_D6, NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_D7, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_DH2, NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_D6, NOTE_D7,
  NOTE_DH3, NOTE_D3, NOTE_D4, NOTE_D3, NOTE_D2, NOTE_DH3, NOTE_DH3, NOTE_DH2,
  NOTE_DH1, NOTE_D3, NOTE_D1, NOTE_D6, NOTE_D5, NOTE_DL5, NOTE_DL4, NOTE_DL5,
  NOTE_DL6, NOTE_D6, NOTE_D7, NOTE_D6, NOTE_D7, NOTE_DL5, NOTE_DL4, NOTE_DL5,
  NOTE_DL6, NOTE_D6, NOTE_D5, NOTE_D6, NOTE_D7, NOTE_D7, NOTE_D6, NOTE_D7,
};
//时值
float duration4[] =
{
  1 + 1, 1 + 1,
  1 + 1, 1 + 1,
  1 + 1, 1 + 1,
  1 + 1, 1 + 1,
  1 + 1, 1 + 1,
  1 + 1, 1 + 1,
  1 + 1, 1 + 1,
  1 + 1, 1 + 1,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  1, 1, 1 + 1,
  1 + 1, 1 + 1,
  1, 1, 1, 1,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
};
//统计音符个数
int length4;*/

//摩斯电码
int scale5[] = {
  Do, Do, O, Do, Do, Do, Do, O,
  Do, Do, Do, O, Do, Do, Do, Do,
  O, Do, O, Do, Do, Do, Do, O,
  Do, Do, Do, O, Do, Do, Do, O,
};
//时值
float duration5[] =
{
  0.5, 0.5, 1.5, 0.5, 1, 0.5, 0.5, 1.5,
  1, 1, 1, 1.5, 0.5, 0.5, 0.5, 1,
  1.5, 0.5, 1.5, 1, 0.5, 1, 1, 1.5,
  1, 1, 1, 1.5, 0.5, 0.5, 1, 1.5,
};
//统计音符个数
int length5;

//----------------------------------------------------------------------------------




//-----------------------------定义模块引脚-----------------------------------------
//--------------------------无源蜂鸣器-------------------------------------------

int Buzzer = 7;          //开机时播报温湿度及空气状况（暂定），收到触摸时随机模拟乐曲

//-------------------PIR-HC501人体红外传感器-----------------------------------

int PIRSensor1 = A2;     //（左眼）指定PIR1模拟端口 A2
int PIRSensor2 = A3;     //（右眼）指定PIR2模拟端口 A3

//-------------------------触摸传感器------------------------------------------

int TouchSensor1 = A4;   //（左小手）指定TouchSensor模拟接口 A4
int TouchSensor2 = A5;   //（右小手）指定TouchSensor模拟接口 A5

//--------------------LED红（爱心，左右脸颊）-----------------------------------

int LEDHeart = 11;       //指定LED端口 11 ,感知到人或收到触摸时亮起，表示温暖,不规则闪烁5s

//-------------------------空气传感器------------------------------------------

int AirSensor = A0;      //检测空气中的有害物质
int Temp = 0;            //临时变量，存储AirSensor读取的数据

//----------------------LED红（口罩，嘴部）-------------------------------------

int LEDAir = 10;         //显示空气状况，规则闪烁3s

//-------------------------温湿度传感器----------------------------------------

int Temper = 5;          //检测温度湿度

//----------------------LED蓝（水滴，额头）-------------------------------------

int LEDWater = 12;       //指定LED端口 12 ,温度湿度低时亮起，提醒喝水保暖，常亮

//------------------------LED红蓝（侧面）---------------------------------------

int LEDTemper = 9;       //显示温湿度状况，规则闪烁3s
int LEDMoisture = 8;     //显示温湿度状况，规则闪烁3s

//-----------------------------------------------------------------------------




//-------------------------定义各函数变量---------------------------------------
int Value1 = 0;          //存储获取到的PIR1数值
int Value2 = 0;          //存储获取到的PIR2数值

int LED = 13;
int Time = 0;            //随机时间
int Times = 0;           //随机次数

//无源蜂鸣器  +  LED  +  空气检测  +  温湿度传感器
//------------------------------------------------------------------------------




//-------------------------------初始化-------------------------------------------
void setup() {
  Serial.begin(9600);          //设置串口波特率为9600
  pinMode(LED, OUTPUT);         //设置13号默认LED为输出模式（测试用）

  pinMode(PIRSensor1, INPUT);   //设置PIR1模拟端口为输入模式
  pinMode(PIRSensor2, INPUT);   //设置PIR2模拟端口为输入模式
  Serial.println("PIRSensor is ready！");

  pinMode(TouchSensor1, INPUT); //设置A4号端口为输入模式
  pinMode(TouchSensor2, INPUT); //设置A5号端口为输入模式
  Serial.println("TouchSensor is ready！");

  pinMode(AirSensor, INPUT);    //定义A0号为INPUT模式
  Serial.println("AIRSensor is ready！");

  pinMode(DHT11PIN, INPUT);     //定义A1号为INPUT模式
  dht.begin();
  Serial.println("DHT11 is ready!");

  pinMode(Buzzer, OUTPUT);
  length1 = sizeof(scale1) / sizeof(scale1[0]); //计算《潮鸣》长度
  length2 = sizeof(tune2) / sizeof(tune2[0]);   //计算《天空之城》长度
  length3 = sizeof(scale3) / sizeof(scale3[0]); //计算《祝你生日快乐》长度
  //length4 = sizeof(tune4) / sizeof(tune4[0]);   //计算《卡农》长度
  Serial.println("Buzzer is ready!");

}
//--------------------------------------------------------------------------------




//------------------------------主函数--------------------------------------------
//主函数，执行顺序：人体红外探测-->空气检测-->温湿度检测-->触摸感应

void loop() {

  //-----------------------------人体红外检测--------------------------------------------
  Value1 = analogRead(PIRSensor1);          //读取A2口的电压值并赋值到value1
  Value2 = analogRead(PIRSensor2);          //读取A3口的电压值并赋值到value1
  //测试用
  Serial.print(Value1);
  Serial.print('\n');
  Serial.print(Value2);
  Serial.print('\n');

  if (Value1 > 150 || Value2 > 150)         //判断PIR1 \ PIR2数值是否大于150，表示人在边缘
  {
    digitalWrite(LED, HIGH);                //满足表示感应到人在边缘

  }
  else if (Value1 > 150 && Value2 > 150)    //判断PIR1 & PIR2数值是否大于150，表示人在中间
  {
    digitalWrite(LED, LOW);                 //满足表示感应到人在中间

  }
  else
  {
    digitalWrite(LED, LOW);                 //表示没有感应到人

  }
  delay(1000);  //扫描延时1s
  //-------------------------------------------------------------------------------------

  //--------------------------------空气检测----------------------------------------------
  Temp = AirDetectation();                    //检测空气质量，是否有有毒气体
  if (Temp >= 90)
  {
    Respirator();                           //执行红色口罩函数
  }
  else
  {

  }
  //测试用
  Serial.print('AirTemp=');
  Serial.println(Temp);
  //--------------------------------------------------------------------------------------

  //--------------------------------温湿度检测--------------------------------------------
  TemperAndMoisture();
  //--------------------------------------------------------------------------------------

  //---------------------------------触摸感应----------------------------------------------
  boolean TouchStat1, TouchStat2;
  TouchStat1 = GetTouch1();
  TouchStat2 = GetTouch2();
  if (TouchStat1 == 1 && TouchStat2 == 0)       //左侧触摸，右侧未触摸
  {
    BlingRedHeart();                            //红心闪烁
  }
  else if (TouchStat2 == 1 && TouchStat2 == 0)  //右侧触摸，左侧未触摸
  {
    digitalWrite(LED, LOW);
    Musics();                                   //执行Musics选歌函数
  }
  else if (TouchStat1 == 1 && TouchStat2 == 1)  //左右都触摸
  {
    digitalWrite(LED, HIGH);
    BlingRedHeart();                            //红心闪烁
    Musics();                                   //执行Musics选歌函数
  }
  else if (TouchStat1 == 0 && TouchStat2 == 0)  //左右都没有触摸
  {

  }
  //测试用
  Serial.print(TouchStat1);
  Serial.print('\n');
  Serial.print(TouchStat2);
  Serial.print('\n');
  delay(200);  //扫描延时0.2s
  //---------------------------------------------------------------------------------------

}
//---------------------------------主函数结束----------------------------------------------




//----------------------------------函数定义------------------------------------------------
//触摸传感器，获取状态函数
boolean GetTouch1()
{
  boolean TouchStat1 = 0;
  TouchStat1 = digitalRead(TouchSensor1); //读入状态1（左）
  return TouchStat1;
}
boolean GetTouch2()
{
  boolean TouchStat2 = 0;
  TouchStat2 = digitalRead(TouchSensor2); //读入状态2（右）
  return TouchStat2;
}



//空气检测函数
int AirDetectation()
{
  int temp = 0;                           //定义临时变量temp
  temp = analogRead(AirSensor);           //读取A0的模拟数据
  delay(500);                             //延时500毫秒
  return temp;
}



//温湿度检测函数
void TemperAndMoisture() {
  //读取数据大约需要250ms，输出的数据大约为前两秒的温湿度（较慢速）
  //读取湿度（百分制）
  float h = dht.readHumidity();
  //读取摄氏温度（默认）
  float t = dht.readTemperature();
  //读取华氏温度(isFahrenheit = true)
  float f = dht.readTemperature(true);

  // 检查是否读取数据失败并提前退出
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  //计算华氏热指数，即体感温度（默认）
  float hif = dht.computeHeatIndex(f, h);
  //计算摄氏热指数，即体感温度(isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  if (h <= 10) {                  //如果湿度<=10%，执行Water和Moisture函数
    Water();
    Moisture();
  }
  if (hic <= 10) {                //如果体感温度（热指数）<=10 *C，执行Temperature函数
    Temperature();
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.print(" *F");
}




//Musics函数，随机播放一首音乐
int Musics()
{
  int m = random(0, 5);                //随机生成0，1，2，3，4五个数，用于选歌
  if (m == 0)                          // m = 0，潮鸣
  {
    //潮鸣
    for (int i = 0; i < length1; i++)
    {
      tone(Buzzer, scale1[i]);
      delay(250 * duration1[i]);
      noTone(Buzzer);
      delay(100);
    }
    delay(3000);                        //音乐结束，安静3s
  }
  else if (m == 1)                      // m = 1，天空之城
  {
    //天空之城
    for (int x = 0; x < length2; x++)   //循环音符的次数
    {
      tone(Buzzer, tune2[x]);           //此函数依次播放tune序列里的数组，即每个 音符
      delay(400 * duration2[x]);        //每个音符持续的时间，即节拍duration，是调整时间的越大，曲子速度越慢，越小曲子速度越快，自己掌握吧
      noTone(Buzzer);                   //停止当前音符，进入下一音符
    }
    delay(3000);                        //音乐结束，安静3秒
  }
  else if (m == 2)                       // m = 2，祝你生日快乐
  {
    for (int x = 0; x < length3; x++)
    {
      tone(Buzzer, scale3[x]);
      delay(500 * duration3[x]); //用来根据节拍调节延时，500这个指数可以自己调整
      delay(100 * duration3[x]);
      noTone(Buzzer);
    }
    delay(3000);                         //音乐结束，安静3秒
  }
  else if(m == 3)                       //hiahiahi，没有音乐
  {
    delay(3000);                        //音乐结束，安静3秒
  }
  /*else if (m == 3)                       // m = 3，卡农
  {
    for (int x = 0; x < length4; x++)
    {
      tone(Buzzer, tune4[x]);
      delay(400 * duration4[x]);
      delay(100 * duration4[x]);
      noTone(Buzzer);
    }
    delay(3000);                         //音乐结束，安静3秒
  }*/
  else if (m == 4)                       // m = 4，摩斯电码“ILOVEYOU”
  {
    for (int i = 0; i < 2; i++)
    {
      for (int x = 0; x < length5; x++)
      {
        tone(Buzzer, scale5[x]);
        delay(500 * duration5[x]);        //根据节拍调节延时，500这个指数可以调整
        delay(100 * duration5[x]);
        noTone(Buzzer);
      }
      delay(2000);                         //一遍结束，安静2秒
    }
    delay(3000);                         //音乐结束，安静3秒
  }
  
}




//红心闪烁函数
int BlingRedHeart()
{
  Times = random(5) * 1000;             //红心，不规则闪烁1-5次,每次闪烁时间1-2s（周期2-3s）
  for (int i = 0; i <= Times; i++)
  {
    digitalWrite(LEDHeart, HIGH);
    Time = ( random(2) + 1 ) * 1000;
    delay(Time);
    digitalWrite(LEDHeart, LOW);
    Time = random(1) * 1000;
    delay(Time);
  }
}




//蓝色水滴常亮函数
int Water()
{
  digitalWrite(LEDWater, HIGH);         //蓝色水滴，常亮
}




//红色口罩闪烁函数
int Respirator()
{
  digitalWrite(LEDAir, HIGH);         //红色口罩，规则闪烁3s（周期6s）
  delay(3000);
  digitalWrite(LEDAir, LOW);
  delay(3000);
}




//红蓝温湿度状况显示双函数
int Temperature()
{
  digitalWrite(LEDTemper, HIGH);      //红色，温度状况显示，规则闪烁1s（周期2s）
  delay(1000);
  digitalWrite(LEDTemper, LOW);
  delay(1000);
}
int Moisture()
{
  digitalWrite(LEDMoisture, HIGH);    //蓝色，湿度状况显示，规则闪烁1s（周期2s）
  delay(1000);
  digitalWrite(LEDMoisture, LOW);
  delay(1000);
}
