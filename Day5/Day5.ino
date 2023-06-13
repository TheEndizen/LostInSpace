int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;

// Relation of dip switch is 6-i, where i is the dip switch identifier
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

void ledCheck() {
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

int power(int base, int exp) {
  int product = 1;
  for(int i = 0; i < exp; i++) {
    product = product*base;
  }
  return product;
}

void displayTotal() {
  // 2^4 => can hold values 0-15
  for (int i = 1; i <= 4; i++) {
    if (digitalRead(6-i) == HIGH) {
      total += power(2, (i-1)); // Take the offset of the pins versus the LED number
    }
    
  }
    Serial.println("The total is");
    Serial.println(total);
    total = 0;
}

void loop() {
  ledCheck();
  displayTotal();
  delay(10000);
}