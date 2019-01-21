#include <SoftwareSerial.h>
// Pin2为RX，接HC05的TXD
// Pin3为TX，接HC05的RXD
SoftwareSerial mySerial(2, 3);
int val = 0;
void setup()
{ Serial.begin(9600);
  pinMode(13, OUTPUT);

  // HC-05默认，9600
  mySerial.begin(9600);
  mySerial.println("BT_is_ready!");
}
void loop()
{
  delay(2000);
  if (Serial.available())
  {
    val = Serial.read();
    mySerial.print(val);
  }
  if (mySerial.available())
  {
    val = mySerial.read();
    Serial.println(val);
  }
  if (val == 49)
  {
    digitalWrite(13, HIGH);
  }
  else if (val == 50)
  {
    digitalWrite(13, LOW);
  }
}
