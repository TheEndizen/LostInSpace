#include <TM1637Display.h>
 
// rotary encoder
#define CLK2 2
#define DT2 3
 
// seven-segment display:
#define CLK 6
#define DIO 5

TM1637Display display = TM1637Display(CLK, DIO);

// Create array that turns all segments on:
const uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
 
// Create array that turns all segments off:
const uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};
 
// You can set the individual segments per digit to spell words or create other symbols:
const uint8_t done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

// step/position counter
int counter = 0;
int currentStateCLK;
int previousStateCLK;
String currentDir ="";

void updateEncoder(){
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK2);
 
  // If last and current state of CLK are different, then a pulse occurred;
  // React to only 0->1 state change to avoid double counting
  if (currentStateCLK != previousStateCLK  && currentStateCLK == 1){
 
    // If the DT state is different than the CLK state then
    // the encoder is rotating CW so INCREASE counter by 1
    if (digitalRead(DT2) != currentStateCLK) {
      counter++;
      currentDir ="CW";
     
    }
    else {
      // Encoder is rotating CCW so DECREASE counter by 1
      counter --;
      currentDir ="CCW";
    }
 
    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter= ");
    Serial.println(counter);
  }
 
  // Remember last CLK state to use on next interrupt...
  previousStateCLK = currentStateCLK;
}


void setup() {
  pinMode(CLK2,INPUT);
  pinMode(DT2,INPUT);
 
  // Setup Serial Monitor
  Serial.begin(9600);
 
  // Read the initial state of A (CLK)
  previousStateCLK = digitalRead(CLK2);
 
  // Clear the display:
  display.clear();
  delay(1000);
  display.setBrightness(7);
 
  // Call Interrupt Service Routine (ISR) updateEncoder() when any high/low change
  // is seen on A (CLK2) interrupt  (pin 2), or B (DT2) interrupt (pin 3)
 
  attachInterrupt(digitalPinToInterrupt(CLK2), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DT2), updateEncoder, CHANGE);
}

void loop() {
  display.showNumberDec(counter);
  delay(50);
 
  if(counter == 50) {
    display.setSegments(data);
    delay(2000);
    display.clear();
  }
 
 if(counter == 75) {
    display.setSegments(data);
    delay(2000);
    display.clear();
  }
 
  if(counter == 100) {
    display.setSegments(done);
    delay(3000);
    display.clear();
    delay(1000);
    display.setSegments(done);
    delay(3000);
    display.clear();
 }
}