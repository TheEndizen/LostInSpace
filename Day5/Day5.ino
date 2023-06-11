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
    //Serial.write("yeet");
    Serial.println(total);
    delay(1000);
  }
}

void displayTotal() {
  int result = total;
  for (int i = 0; i< 4; ++) {
    result = result%2;
    if (result == 0) {
      
    }
  }
}


void loop() {
  // half byte register
  calculator();
  displayTotal();

}