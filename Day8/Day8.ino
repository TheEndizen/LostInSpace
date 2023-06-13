// pins able to use pwm are marked with a tilde (~)
// alternative set of pins is {3, 5, 6}
int red = 11;
int green = 10;
int blue = 9;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void rgbColour(int redVal, int greenVal, int blueVal) {
  // introduction to pulse width modulation (PWM) -> turning a digital output on and off for a specified duration
  // technique to produce analog results with digital means
  // we cannot change the level of voltage but we can change the duration of the digital output (essentially analogWrite() for the digital pin)

  // recall rgb values range from 0 to 255
  // pulse is the "on time"
  // see https://docs.arduino.cc/learn/microcontrollers/analog-output
  analogWrite(red, redVal);
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
}


void loop() {
  // rotate through a bunch of colors
  rgbColour(255, 0, 0); // red
  delay(1000);
  rgbColour(0, 255, 0); // green
  delay(1000);
  rgbColour(0, 0, 255); // blue
  delay(1000);
  rgbColour(125, 125, 0); // yellow
  delay(1000);
  rgbColour(125, 0, 125); // purple
  delay(1000);
  rgbColour(0, 125, 125); // cyan
  delay(1000);
  rgbColour(125, 125, 125); // white
  delay(1000);
}
