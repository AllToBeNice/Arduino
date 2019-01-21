#define TouchSensor A5

//获取状态
boolean GetTouch(){
  boolean TouchStat=0;
  TouchStat=digitalRead(TouchSensor);//读入状态
  return TouchStat;
}
 
void setup() {
  pinMode(TouchSensor,INPUT);       //设置A5号端口为输入模式
  Serial.begin(115200);
}
 
void loop() {
  boolean TouchStat;
  Serial.print("\nrunning\nTouch Stat - ");
  TouchStat=GetTouch();
  Serial.print(TouchStat);
  delay(200);
}
