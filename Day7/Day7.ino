int sensorPin = A0;
int sensorValue = 0;

unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double percentCharged;

void setup() {
  Serial.begin(9600);
  Serial.println("photoresistor data");
}

void displayBatteryPercentage() {
  percentCharged = (double)batteryLevel / (double)batteryCapacity * 100;
  Serial.print(percentCharged);
  Serial.println("%"); // creates new line
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("charge increase: ");
  Serial.println(sensorValue);

  if (batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.println("ms taken.");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity;
    ticks = 0;
    delay(30000); // arbitrarily large wait time
  }
  else {
    displayBatteryPercentage();
  }

  // simulate battery charge
  batteryLevel += sensorValue;
  ticks += wait;

  delay(wait); // increase every 100ms
}
