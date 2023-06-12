int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;

int DIP1 = 5;
int DIP2 = 4;
int DIP3 = 3;
int DIP4 = 2;

int input = 0;
int total = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(DIP1, INPUT);
  pinMode(DIP2, INPUT);
  pinMode(DIP3, INPUT);
  pinMode(DIP4, INPUT);
}

void calculator() {
  if (digitalRead(DIP1) == HIGH) {
    input = 1;
    total += input;
    Serial.println(total);
    delay(1000);
  }
}

void displayTotal() {
  int result = total%16; // 2^4 => can hold values 0-15
  for (int i = 1; i <= 4; i++) {
    result = result%2;
    if (result == 1) {
      digitalWrite(6-i, HIGH); // Take the offset of the pins versus the LED number
    }
    else {
      digitalWrite(6-i, LOW);
    }
  }
}

void loop() {
  // half byte register
  calculator();
  displayTotal();
}