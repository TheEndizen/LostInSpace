int sensorPin = A0;
int sensorValue = 0;

// default pin for LED_BUILTIN on Arduino UNO
int onboardLED = 13;

void setup() {
  Serial.begin(9600);
  Serial.write("photoresistor data");
  delay(1000);
  pinMode(onboardLED, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  
  // blink LED depending on resistance
  // high resistance when bright => slower blinks
  // low resistance when dark => quicker blinks
  digitalWrite(onboardLED, HIGH);
  delay(sensorValue);
  digitalWrite(onboardLED, LOW);
  delay(sensorValue);

  // print data
  Serial.println(sensorValue);
}
