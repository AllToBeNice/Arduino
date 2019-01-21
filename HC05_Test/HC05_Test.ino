int p = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);              // 打开串口（蓝牙）
  pinMode(11, OUTPUT);             // 定义11脚为输出.
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {   // 串口收到字符数大于零。
    p = Serial.parseInt();           // 在串口数据流中查找一个有效整数。
    if (Serial.read() == 'X') {      // 收到结束符后开始处理数据。
      
      switch (p) {                   // 判断数据内容。
        case 1:
          digitalWrite(13, HIGH);      // 点亮LED。
          Serial.println(p);           // 回传数据。
          Serial.print(1313);
          break;
        case 2:
          digitalWrite(13, LOW);       // 熄灭LED。
          Serial.println(p);           // 回传数据。
          Serial.print(2424);
          break;
        default:
          analogWrite(13, LOW);          // 调整LED亮度。
      }
    }
  }
}
