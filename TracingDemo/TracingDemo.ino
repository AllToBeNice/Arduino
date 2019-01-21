//TracingDemo

int inputpin = 7;
int outputpin = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(inputpin,INPUT);
  pinMode(outputpin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outputpin,LOW);
  delayMicroseconds(2);
  digitalWrite(outputpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(outputpin,LOW);
  delayMicroseconds(2);
  double distance = pulseIn(inputpin,HIGH);
  distance = distance/58;
  Serial.println(distance);
  if(distance >=10)
  {
    digitalWrite(13,HIGH);
    delay(300);
    digitalWrite(13,LOW);
    delay(300);
    }
    else
    {
      digitalWrite(13,HIGH);
      delay(300);
      digitalWrite(13,LOW);
      delay(3000);
      }
      
}
