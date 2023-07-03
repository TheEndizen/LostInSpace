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
 
// define a password set
const byte passLength = 4;
char password[passLength] = {'0','0','0','0'};

void passReset() {
  Serial.println("Please enter a new password: ");

  char input = matrix.getKey();
  for (byte i = 0; i < passLength; i++) {
    while(  !( input = matrix.getKey() )  ) {
      // wait indefinitely for keypad input of any kind
    }
    password[i] = input;
    Serial.print("*");
  }
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
    Serial.print("*");
    if (input != password[i]) {
      Serial.println("");
      Serial.println("Incorrect password.");
      return; // stop as soon as the password is incorrect
    }
  }
  Serial.println("");
  Serial.println("Correct password.");
}

void setup() {
  Serial.begin(9600);
  delay(2000);
  
  Serial.println("Enter * to set the password");
  Serial.println("Enter # to access the system.");
  Serial.println("Please select an option.");
}

void loop() {
  char input = matrix.getKey();

  if (input == '*') {
    delay(500);
    passReset();
  }
  else if (input == '#') {
    delay(500);
    passEnter();
  }

}
