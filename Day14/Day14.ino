#include <Key.h>
#include <Keypad.h>

// byte data type is equivalent to size of unsigned char on compiler
const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 12, 13};

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad matrix = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS); // library function
 
// define a password set
const byte passLength = 4;
char password[passLength] = {'0','0','0','0'};


// add visual feedback (pwm led pins)
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

// add audio feedback (piezo output pins)
int buzzer = 8;

void passReset() {
  Serial.println("Please enter a new password: ");

  char input = matrix.getKey();
  for (byte i = 0; i < passLength; i++) {
    while(  !( input = matrix.getKey() )  ) {
      // wait indefinitely for keypad input of any kind
    }
    playInput();
    password[i] = input;
    Serial.print("*");
  }
  playSuccess();
  Serial.println("");
  Serial.println("Password changed successfully.");
  setup();
}

void passEnter() {
  char input = matrix.getKey();
  Serial.println("Please enter the password.");
  for (byte i = 0; i < passLength; i++) {
    while (  !( input = matrix.getKey() )  ) {
      // wait for an input
    }
    playInput();
    Serial.print("*");
    if (input != password[i]) {
      playError();
      Serial.println("");
      Serial.println("Incorrect password.");
      setup();
      return; // stop as soon as the password is incorrect
    }
  }
  playSuccess();
  Serial.println("");
  Serial.println("Correct password.");
}

// custom color using pwm
void rgbColour(int redVal, int greenVal, int blueVal) {
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}

void playInput() {
  tone(buzzer, 880, 200);
  delay(50);
  noTone(buzzer);
}

void playError() {
  rgbColour(125, 0, 0);
  tone(buzzer, 147, 200);
  delay(100);
  noTone(buzzer);
  rgbColour(0, 0, 0);
}

void playSuccess() {
  rgbColour(0, 125, 0);
  tone(buzzer, 1000, 200);
  delay(200);
  tone(buzzer, 2700, 1000);
  delay(1000);
  noTone(buzzer);
  rgbColour(0, 0, 0);
}


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  rgbColour(0, 0, 0);


  Serial.begin(9600);
  delay(2000);
  
  Serial.println("Enter * to set the password");
  Serial.println("Enter # to access the system.");
  Serial.println("Please select an option.");
}

void loop() {
  char input = matrix.getKey();
  playInput();
  
  if (input == '*') {
    delay(500);
    passReset();
  }
  else if (input == '#') {
    delay(500);
    passEnter();
  }

}