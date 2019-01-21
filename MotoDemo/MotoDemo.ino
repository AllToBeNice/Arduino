int LeftMotor1 =  4;  //左侧，前，电机
int LeftMotor2 =  5;  //左侧，后，电机
int RightMotor1 = 6; //右侧，前，电机
int RightMotor2 = 7;//右侧，后，电机
int ENA = 10;
int ENB = 11;

void setup() {
  // put your setup code here, to run once:
  //测速引脚初始化
  pinMode(LeftMotor1, OUTPUT);
  pinMode(LeftMotor2, OUTPUT);
  pinMode(RightMotor1, OUTPUT);
  pinMode(RightMotor2, OUTPUT);
  pinMode(10, OUTPUT); //设置数字端口10  11为输出模式
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  delayMicroseconds(400); // 大约10%占空比的1KHz方波
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  delayMicroseconds(600);
  /*/digitalWrite(LeftMotor1, HIGH);
  digitalWrite(LeftMotor2, LOW);
  digitalWrite(RightMotor1, LOW);
  digitalWrite(RightMotor2, LOW);
  delay(2000);*/

  /*/后轮驱动
    digitalWrite(LeftMotor1, LOW);
    digitalWrite(LeftMotor2, HIGH);
    digitalWrite(RightMotor1, LOW);
    digitalWrite(RightMotor2, HIGH);

    //左转
    digitalWrite(LeftMotor1, HIGH);
    digitalWrite(LeftMotor2, LOW);
    digitalWrite(RightMotor1, LOW);
    digitalWrite(RightMotor2, HIGH);

    //右转
    digitalWrite(LeftMotor1, LOW);
    digitalWrite(LeftMotor2, HIGH);
    digitalWrite(RightMotor1, HIGH);
    digitalWrite(RightMotor2, LOW);

    digitalWrite(LeftMotor1, LOW);
    digitalWrite(LeftMotor2, LOW);
    digitalWrite(RightMotor1, LOW);
    digitalWrite(RightMotor2, LOW);*/
}
