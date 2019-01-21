//TracDemo,pin = 10
void setup() {
  // put your setup code here, to run once:
  pinMode(10,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a;
  a = digitalRead(10);
  if(a==0)
  {
    Serial.println("HelloWorld!");
    }
   if(a==1)
   {
    Serial.println("OOOOOH");
    }
}
