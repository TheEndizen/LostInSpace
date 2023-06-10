int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;

int DIP1 = 5;
int DIP2 = 4;
int DIP3 = 3;
int DIP4 = 2;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(DIP1, INPUT);
  pinMode(DIP2, INPUT);
  pinMode(DIP3, INPUT);
  pinMode(DIP4, INPUT);
}

void loop() {
  if (digitalRead(DIP1) == HIGH) {
    digitalWrite(LED1, HIGH);
  }
  else {
    digitalWrite(LED1, LOW); // turn LED off
  }

  if (digitalRead(DIP2) == HIGH) {
    digitalWrite(LED2, HIGH);
  }
  else {
    digitalWrite(LED2, LOW); // turn LED off
  }
  
  if (digitalRead(DIP3) == HIGH) {
    digitalWrite(LED3, HIGH);
  }
  else {
    digitalWrite(LED3, LOW); // turn LED off
  }
  
  if (digitalRead(DIP4) == HIGH) {
    digitalWrite(LED4, HIGH);
  }
  else {
    digitalWrite(LED4, LOW); // turn LED off
  }
}