
//-------------------------触摸传感器------------------------------------------
int TouchSensor1 = A4;   //（左小手）指定TouchSensor模拟接口 A4
int TouchSensor2 = A5;   //（右小手）指定TouchSensor模拟接口 A5


int Value1 = 0;          //存储获取到的PIR1数值
int Value2 = 0;          //存储获取到的PIR2数值

int LED = 13;
int Time = 0;            //随机时间
int Times = 0;           //随机次数


void setup() {
  Serial.begin(9600);          //设置串口波特率为9600
  // put your setup code here, to run once:
  pinMode(TouchSensor1, INPUT); //设置A4号端口为输入模式
  pinMode(TouchSensor2, INPUT); //设置A5号端口为输入模式
  Serial.println("TouchSensor is ready！");
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, LOW);
  // put your main code here, to run repeatedly:
  //触摸感应
  boolean TouchStat1, TouchStat2;
  //Serial.print("running\nTouch Stat - ");
  TouchStat1 = GetTouch1();
  TouchStat2 = GetTouch2();

  if (TouchStat1 == 1 && TouchStat2 == 0)       //左侧触摸，右侧未触摸
  {
    //BlingRedHeart();                            //红心闪烁
  }
  else if (TouchStat2 == 1 && TouchStat2 == 0)  //右侧触摸，左侧未触摸
  {
    digitalWrite(LED, LOW);
  }
  else if (TouchStat1 == 1 && TouchStat2 == 1)  //左右都触摸
  {
    digitalWrite(LED, HIGH);
  }
  else if (TouchStat1 == 0 && TouchStat2 == 0)  //左右都没有触摸
  {

  }
  Serial.println(TouchStat1);//测试用
  //Serial.print('\n');
  Serial.println(TouchStat2);
  //Serial.print('\n');
  Serial.print('TouchStat1=');
  Serial.print(TouchStat1);
  Serial.print(',');
  Serial.print('TouchStat2=');
  Serial.print(TouchStat2);
  Serial.print('\n');
  delay(200);  //扫描延时0.2s
}



//触摸传感器，获取状态函数
boolean GetTouch1()
{
  boolean TouchStat1 = 0;
  TouchStat1 = digitalRead(TouchSensor1); //读入状态1
  return TouchStat1;
}
boolean GetTouch2()
{
  boolean TouchStat2 = 0;
  TouchStat2 = digitalRead(TouchSensor2); //读入状态2
  return TouchStat2;
}
