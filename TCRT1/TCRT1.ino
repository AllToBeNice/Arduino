
void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(300);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data[0];
  int TCRT1 = 10;
  data[0] = digitalRead(10);
  Serial.print(data[0]);
  Serial.print("---");
  if(data[0]==HIGH)
  {
    Serial.println("HelloWorld!");
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    }
   if(data[0]==LOW)
   {
    digitalWrite(13,HIGH);
    delay(3000);
    digitalWrite(13,LOW);
    delay(3000);
    }
}
