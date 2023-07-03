#include <Key.h>
#include <Keypad.h>

// byte data type is equivalent to unsigned char on compiler
const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad matrix = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS); // library function

// assign a frequency to each tone
int tones[ROWS][COLS] = {
  {31, 93, 147, 208},
  {247, 311, 370, 440},
  {523, 587, 698, 880},
  {1397, 2637, 3729, 4978}
};

// pin requires pulse width modulation
int buzzer = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int toneFreq = 0; // no frequency, ie. muted at the start
  char input = matrix.getKey(); // button press

// set the corresponding tone to the button
  if (input) {
    for (byte i = 0; i < ROWS; i++) {
      for (byte j = 0; j < COLS; j++) {
        if (input == buttons[i][j]) {
          toneFreq = tones[i][j];
        }
      }
    }

    // print to serial monitor
    Serial.print("Key: ");
    Serial.print(input);
    Serial.print('\t');
    Serial.print("Freq: ");
    Serial.println(toneFreq);
 
    tone(buzzer, toneFreq, 500);  // ... and play the tone for a half second
    delay(500);
    noTone(buzzer);
  }
}
