// seven-segment display library
#include <TM1637Display.h>

#define CLK 6 // clock
#define DIO 5 // digital input and output

// create object
TM1637Display display = TM1637Display(CLK, DIO);

// each segment of each digit is represented as a bit in the 8 bit sequence
// hex FF <=> bin 11111111 <=> dec 255
// hex 0 <=> bin 0 <=> dec 0
const uint8_t data[] =   {0xFF, 0xFF, 0xFF, 0xFF};
const uint8_t blank[]  = {0x00, 0x00, 0x00, 0x00};

// use bitwise operators to set
// SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G
const uint8_t dead[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G
};

const uint8_t beef[] = {
  SEG_C | SEG_D | SEG_E | SEG_F | SEG_G, 
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,
  SEG_A | SEG_E | SEG_F | SEG_G
};


void setup() {
  display.clear();          // reset display
  display.setBrightness(0); // set the brightness, or nothing will show. Ranges from 0 to 7
  delay(1000);
}


void loop() {
  // blink sequence
  display.setSegments(data);
  delay(1000);
  display.clear();
  delay(2000);
  display.setSegments(data);
  delay(1000);

  int i;
  for (i = 0; i <= 100; i++) {
    display.showNumberDec(i);  // this knows how to make decimal numbers
    delay(100);
  }
  display.setSegments(dead);
  delay(1000);
  display.setSegments(beef);
  delay(1000);

  while(1); // stop here
}