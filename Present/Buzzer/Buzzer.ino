
//------------宏定义-------------------------------------------
//潮鸣---------------------------------------------------------
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
//----------------------------------------------------------------------------
//天空之城--------------------------------------------------------------------
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

//这部分是用英文对应了拍子
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
//-----------------------------------------------------------------------
//生日快乐---------------------------------------------------------------
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
//----------------------------------------------------------------------------
//卡农------------------------------------------------------------------------
#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 112

#include <avr/pgmspace.h>
//潮鸣--------------------------------------------------------------------------
//旋律
int scale1[] = {G, A, EE, A, G, A, G, A, EE, A, G,
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
float duration1[] = {2, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1,
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
//天空之城------------------------------------------------------------------------
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

//生日快乐-------------------------------------------------------------------------
//旋律
int scale3[] = {Sol, Sol, La, Sol, Do_h, Si,
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

//卡农------------------------------------------------------------------------
//旋律
int tune4[] =
{
  NTDH3, NTDH2,
  NTDH1, NTD7,
  NTD6, NTD5,
  NTD6, NTD7,
  NTDH1, NTD7,
  NTD6, NTD5,
  NTD4, NTD3,
  NTD4, NTD2,
  NTDH1, NTD7, NTDH1, NTD1, NTDL7, NTD5, NTD2, NTD3,
  NTD1, NTDH1, NTD7, NTD6, NTD7, NTDH3, NTDH5, NTDH6,
  NTDH4, NTDH3, NTDH2, NTDH4, NTDH4, NTDH3, NTDH1, NTD7,
  NTD6, NTD5, NTD4, NTD3, NTD2, NTD4, NTD3, NTD2,
  NTD1, NTD2, NTD3, NTD4, NTD5, NTD2, NTD5, NTD4,
  NTD3, NTD6, NTD5, NTD4, NTD5, NTD4, NTD3, NTD2,
  NTD1, NTDL6, NTD6, NTD7, NTDH1, NTD7, NTD6, NTD5,
  NTD4, NTD3, NTD2, NTD6, NTD5, NTD6, NTD5, NTD4,
  NTD3, NTDH3, NTDH2,
  NTDH1, NTDH2,
  NTDH1, NTDH3, NTDH2, NTDH4,
  NTDH5, NTDH3, NTDH4, NTDH5, NTDH3, NTDH4, NTDH5, NTD5, NTD6, NTD7, NTDH1, NTDH2, NTDH3, NTDH4,
  NTDH3, NTDH1, NTDH2, NTDH3, NTD3, NTD4, NTD5, NTD6, NTD5, NTD4, NTD5, NTD3, NTD4, NTD5,
  NTD4, NTD6, NTD5, NTD4, NTD3, NTD2, NTD3, NTD2, NTD1, NTD2, NTD3, NTD4, NTD5, NTD6,
  NTD4, NTD6, NTD5, NTD6, NTD7, NTDH1, NTD5, NTD6, NTD7, NTDH1, NTDH2, NTDH3, NTDH4, NTDH5,
  NTDH3, NTDH1, NTDH2, NTDH3, NTDH2, NTDH1, NTDH2, NTD7, NTDH1, NTDH2, NTDH3, NTDH2, NTDH1, NTD7,
  NTDH1, NTD6, NTD7, NTDH1, NTD1, NTD2, NTD3, NTD4, NTD3, NTD2, NTD3, NTDH1, NTD7, NTDH1,
  NTD6, NTDH1, NTD7, NTD6, NTD5, NTD4, NTD5, NTD4, NTD3, NTD4, NTD5, NTD6, NTD7, NTD1,
  NTD6, NTDH1, NTD7, NTDH1, NTD7, NTD6, NTD7, NTDH1, NTDH2, NTDH1, NTD7, NTDH1, NTD6, NTD7,
  NTDH3, NTD3, NTD4, NTD3, NTD2, NTDH3, NTDH3, NTDH2,
  NTDH1, NTD3, NTD1, NTD6, NTD5, NTDL5, NTDL4, NTDL5,
  NTDL6, NTD6, NTD7, NTD6, NTD7, NTDL5, NTDL4, NTDL5,
  NTDL6, NTD6, NTD5, NTD6, NTD7, NTD7, NTD6, NTD7,
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
int length4;


int Buzzer = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer, OUTPUT);
  //length1 = sizeof(scale1) / sizeof(scale1[0]); //计算《潮鸣》长度
  //length2 = sizeof(tune2) / sizeof(tune2[0]);   //计算《天空之城》长度
  length3 = sizeof(scale3) / sizeof(scale3[0]); //计算《祝你生日快乐》长度
  length4 = sizeof(tune4) / sizeof(tune4[0]);   //计算《卡农》长度

  Serial.begin(9600);          //设置串口波特率为9600
}

void loop() {
  // put your main code here, to run repeatedly:
  int m = 0;
  m = random(0, 5);                //随机生成0，1，2，3，4五个数，用于选歌
  if (m == 0)                           // m = 0，潮鸣
   {
    //潮鸣
    for (int i = 0; i < length1; i++) {
      tone(Buzzer, scale1[i]);
      delay(250 * duration1[i]);
      noTone(Buzzer);
      delay(100);
    }
    delay(3000);
  }
  else if (m == 1)                       // m = 1，天空之城
  {
    //天空之城
    for (int x = 0; x < length2; x++)   //循环音符的次数
    {
      tone(Buzzer, tune2[x]);           //此函数依次播放tune序列里的数组，即每个 音符
      delay(400 * duration2[x]);        //每个音符持续的时间，即节拍duration，是调整时间的越大，曲子速度越慢，越小曲子速度越快
      noTone(Buzzer);                   //停止当前音符，进入下一音符
    }
    delay(3000);                        //等待5秒后，循环重新开始
  }
  else if (m == 2)                       // m = 2，祝你生日快乐
  {
    for (int x = 0; x < length3; x++)
    {
      tone(Buzzer,scale3[x]);
      delay(500 * duration3[x]); //用来根据节拍调节延时，500这个指数可以自己调整
      delay(100 * duration3[x]);
      noTone(Buzzer);
    }
    delay(3000);
  }
  else if (m == 3)                       // m = 3，卡农
  {
    for (int x = 0; x < length4; x++)
    {
      tone(Buzzer, tune4[x]);
      delay(400 * duration4[x]);
      delay(100 * duration4[x]);
      noTone(Buzzer);
    }
    delay(3000);
  }
  else if (m == 4)                       // m = 4，
  {

  }
}
