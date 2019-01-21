int SoundsSensor = A2; // select the input pin for the potentiometer
int LEDPin = 13; // select the pin for the LED
int SensorValue = 0; // variable to store the value coming from the sensor

void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  SensorValue = analogRead(SoundsSensor);
  digitalWrite(LEDPin, HIGH);
  delay(SensorValue);
  digitalWrite(LEDPin, LOW);
  delay(SensorValue);
  Serial.println(SensorValue, DEC);
}
