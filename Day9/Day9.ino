// day 6
int sensorPin = A0;   // pin gets data from sensor
int sensorValue = 0;  // value of data from sensor
 
//day 7
unsigned int batteryCapacity = 50000; // maximum battery level
unsigned int batteryLevel = 0;        // current battery level
unsigned int ticks = 0;               // time taken in ms
unsigned int wait = 100;              // step counter for time taken
double percentCharged;                // current percent charged

// day 8
// pwm pins for rgb led
int red = 11;
int green = 10;
int blue = 9;

void rgbColour(int redVal, int greenVal, int blueVal) {
  analogWrite(red, redVal);
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
}

double displayBatteryPercentage() {
  percentCharged = (double)batteryLevel / (double)batteryCapacity * 100;

  // print elapsed time
  Serial.print(ticks);
  Serial.println("ms taken.");

  // print percent charge
  Serial.print(percentCharged);
  Serial.println("%"); // creates new line

  // set the LED to match the corresponding level of battery percentage
  // use switch cases
}

void setup() {
  // set pwm pins
  pinMode(red, OUTPUT);   
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT);  

  // turn on serial monitor
  Serial.begin(9600);     
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("charge increase: ");
  Serial.println(sensorValue);

  if (batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.println("ms taken.");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity;
    ticks = 0;
    rbgColour(0, 125, 0); // display green for fully charged
    delay(30000); // arbitrarily large wait time
  }
  else {
    displayBatteryPercentage();
  }

  // simulate battery charge
  batteryLevel += sensorValue;
  ticks += wait;

  delay(wait); // increase every 100ms
}
