//int light = 12; // Refers to HERO board pin 12
#define light 12

void setup() {
  // Initialize the HERO...
  pinMode(light, OUTPUT); // pinMode assigns a function to a pin
  //digitalWrite(light, HIGH); // LOW and HIGH are used to indicate 0V or 5V
}

void loop() {
  // the code placed here will run repeatedly until HERO is turned off:
  digitalWrite(light, LOW);
  delay(1000);
  digitalWrite(light, HIGH);
  delay(1000);
}
