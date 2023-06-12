int sensorPin = A0;
int sensorValue = 0;

int onboardLED = 13;

void setup() {
  Serial.begin(9600);
  Serial.write("photoresistor data");
  delay(1000);
  pinMode(onboardLED, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(1000);

}
