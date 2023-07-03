#include <Key.h>
#include <Keypad.h>

// byte synonymous with short or char (?)
const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {8, 9, 10, 11};

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad matrix = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS); // library function

void setup() {
  Serial.begin(9600);
}

void loop() {
  char input = matrix.getKey();
  if (input) {
    Serial.println(input);
  }
}
