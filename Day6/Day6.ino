int sensorPin = A0;
int sensorValue = 0;
int onboardPin = 13;
// default pin 13 is used for LED_BUILTIN on Arduino UNO
void setup() {
  Serial.begin(9600);
  Serial.write("photoresistor data");
  pinMode(onboardPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  
  // blink LED depending on resistance
  // high resistance when bright => slower blinks
  // low resistance when dark => quicker blinks
  digitalWrite(onboardPin, HIGH);
  delay(sensorValue);
  digitalWrite(onboardPin, LOW);
  delay(sensorValue);

  // print data
  Serial.println(sensorValue);
  delay(1000);
}
