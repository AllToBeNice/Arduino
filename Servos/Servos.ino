#include <Servo.h>
#define angle1 10
#define angle2 0
Servo myservo1;//底盘（左右）
Servo myservo2;//基部（上下）,连接左右两个舵机，同时控制
Servo myservo3;//机械爪（抓取）
int pos = 0;
void setup() {
  myservo1.attach(3);//设定接口
  myservo2.attach(5);
  myservo3.attach(6);
  //设定引脚
  pinMode(8, OUTPUT);//基部
  pinMode(9, OUTPUT);//底盘
  pinMode(10, OUTPUT);//机械爪
  Serial.begin(9600);
}
void loop() {
  int a, b, c, d, e;
  a = map(analogRead(A0), 0, 1023, 180, 0);
  b = map(analogRead(A1), 0, 1023, 180, 0);
  c = map(analogRead(A2), 0, 1023, 180, 0);
  d = map(analogRead(A3), 0, 1023, 0, 180);
  e = digitalRead(A4);
  myservo1.write(a);
  myservo2.write(b);
  myservo3.write(c);
  if (d <= 70) {
    digitalWrite(9, 0);
    digitalWrite(10, 1);
  } else if (d > 70 || d < 110) {
    digitalWrite(9, 0);
    digitalWrite(10, 0);
  } else if (d >= 110) {
    digitalWrite(9, 1);
    digitalWrite(10, 0);
  } digitalWrite(8, e);


  Serial.print(" a , b , c , d ,e");
  Serial.println();
  Serial.print(a);
  Serial.print(",");
  Serial.print(b);
  Serial.print(",");
  Serial.print(c);
  Serial.print(",");
  Serial.print(d);
  Serial.print(",");
  Serial.println(e);
  delay(100);
}

void Servos() {
  int B;
  B = Serial.read();
  if (B == 5) {
    myservo1.write(angle1);//右转
  } else if (B == 6) {
    myservo1.write(angle2);//左转
  } else if (B == 7) {
    myservo2.write(angle1);//向前
  } else if (B == 8) {
    myservo2.write(angle2);//向后
  } else if (B == 9) {
    myservo3.write(angle1);//抓取
  } else if (B == 10) {
    myservo3.write(angle2);//松开
  }
}
