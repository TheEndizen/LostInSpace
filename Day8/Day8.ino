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
  // technique to produce analog-like signals with digital pins to be sent to components
  // recall rgb values range from 0 to 255
  analogWrite(red, redVal);
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
}


void loop() {
  // rotate through a bunch of colors
  rgbColour(125, 255, 255); // Red
  delay(1000);
  rgbColour(255, 125, 255); // Green
  delay(1000);
  rgbColour(255, 255, 125); // Blue
  delay(1000);
  rgbColour(125, 125, 255); // yellow
  delay(1000);
  rgbColour(125, 255, 125); // purple
  delay(1000);
  rgbColour(125, 125, 125); // white
  delay(1000);
}
