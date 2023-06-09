int LED = 12;
int DIP = 2;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(DIP, INPUT);
}

void loop() {
  if (digitalRead(DIP) == HIGH) {
    digitalWrite(LED, LOW); // turn LED on
    delay(1000);
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(100);
  }
  else {
    digitalWrite(LED, LOW); // turn LED off
  }

}
