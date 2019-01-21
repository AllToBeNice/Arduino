#define Aout A0 //MQ-135 AO 接 A0
 
int temp = 0; //临时变量，存储A0读取的数据
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//定义波特率
  pinMode(Aout, INPUT);//定义A0为INPUT模式
}
 
void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(Aout); //读取A0的模拟数据
  Serial.println(temp); //串口输出temp的数据
  delay(500);  //延时500毫秒
}
