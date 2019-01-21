#include <Servo.h>
int motorL1=7; //左边轮子
int motorL2=8;
int motorR1=12; //右边轮子
int motorR2=13;
int trig=11; //发射信号
int echo=10; //接收信号
unsigned int S; //距离存储
void setup() {
Serial.begin(9600); //设置波特率
pinMode(trig,OUTPUT); //设置引脚模式
pinMode(echo,INPUT);
pinMode(motorL1,OUTPUT);
pinMode(motorL2,OUTPUT);
pinMode(motorR1,OUTPUT);
pinMode(motorR2,OUTPUT);
tone(12,800,500);
delay(2000); //开机延时
}


void loop() { //主函数
range();  //执行测距函数
//if(S<20){ //判断障碍物距离，距离太近
//line(); //后退
//}
line();
if(S>100){ //距离中等
R(); //运行转向判断函数
}
//if(S>20&&S<=80){ //距离充足
//line(); //运行直行函数
//}
else lull();
}

void range(){ //测距函数
digitalWrite(trig,LOW); //测距
delayMicroseconds(2); //延时2微秒
digitalWrite(trig,HIGH);
delayMicroseconds(20);
digitalWrite(trig,LOW);
int distance = pulseIn(echo,HIGH); //读取高电平时间
distance = distance/58; //按照公式计算
S = distance; //把值赋给S
Serial.println(S); //向串口发送S的值，可以在显示器上显示距离
delay(50); //延时

}


void line(){
digitalWrite(motorR1,LOW); //启动所有电机向前
digitalWrite(motorL1,LOW);
digitalWrite(motorR2,HIGH);
digitalWrite(motorL2,HIGH);
}
void R(){
digitalWrite(motorL2,LOW);
digitalWrite(motorR1,LOW);
analogWrite(motorL1,LOW);
analogWrite(motorR2,HIGH);
lull();
}


void back(){ //后退函数
digitalWrite(motorL1,HIGH);
digitalWrite(motorR1,HIGH);
digitalWrite(motorL2,LOW);
digitalWrite(motorR2,LOW);
}

void lull(){
digitalWrite(motorL1,LOW);
digitalWrite(motorL2,LOW);
digitalWrite(motorR1,LOW);
digitalWrite(motorR2,LOW);
}
