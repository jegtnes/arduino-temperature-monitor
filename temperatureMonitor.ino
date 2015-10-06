/*
SparkFun Inventor's Kit
Example sketch 07

TEMPERATURE SENSOR

  Use the "serial monitor" window to read a temperature sensor.
  
  The TMP36 is an easy-to-use temperature sensor that outputs
  a voltage that's proportional to the ambient temperature.
  You can use it for all kinds of automation tasks where you'd
  like to know or control the temperature of something.
  
  More information on the sensor is available in the datasheet:
  http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Temp/TMP35_36_37.pdf

  Even more exciting, we'll start using the Arduino's serial port
  to send data back to your main computer! Up until now, we've 
  been limited to using simple LEDs for output. We'll see that
  the Arduino can also easily output all kinds of text and data.
  
Hardware connections:

  Be careful when installing the temperature sensor, as it is
  almost identical to the transistors! The one you want has 
  a triangle logo and "TMP" in very tiny letters. The
  ones you DON'T want will have "222" on them.

  When looking at the flat side of the temperature sensor
  with the pins down, from left to right the pins are:
  5V, SIGNAL, and GND.
  
  Connect the 5V pin to 5 Volts (5V).
  Connect the SIGNAL pin to ANALOG pin 0.
  Connect the GND pin to ground (GND).

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/

// We'll use analog input 0 to measure the temperature sensor's
// signal pin.

const int temperaturePin = 0;

const int teensPin    = 11;
const int twentiesPin = 12;
const int thirtiesPin = 13;

const int onePin   = 10; // When using serial we apparently can't use pin 0 and 1 ¯\_(ツ)_/¯
const int twoPin   = 2;
const int threePin = 3;
const int fourPin  = 4;
const int fivePin  = 5;
const int sixPin   = 6;
const int sevenPin = 7;
const int eightPin = 8;
const int ninePin  = 9;


void setup()
{

  pinMode(onePin, OUTPUT);
  pinMode(twoPin, OUTPUT);
  pinMode(threePin, OUTPUT);
  pinMode(fourPin, OUTPUT);
  pinMode(fivePin, OUTPUT);
  pinMode(sixPin, OUTPUT);
  pinMode(sevenPin, OUTPUT);
  pinMode(eightPin, OUTPUT);
  pinMode(ninePin, OUTPUT);
  pinMode(teensPin, OUTPUT);
  pinMode(twentiesPin, OUTPUT);
  pinMode(thirtiesPin, OUTPUT);

  digitalWrite(onePin, LOW);
  digitalWrite(twoPin, LOW);
  digitalWrite(threePin, LOW);
  digitalWrite(fourPin, LOW);
  digitalWrite(fivePin, LOW);
  digitalWrite(sixPin, LOW);
  digitalWrite(sevenPin, LOW);
  digitalWrite(eightPin, LOW);
  digitalWrite(ninePin, LOW);
  digitalWrite(teensPin, LOW);
  digitalWrite(twentiesPin, LOW);
  digitalWrite(thirtiesPin, LOW);

  // In this sketch, we'll use the Arduino's serial port
  // to send text back to the main computer. For both sides to
  // communicate properly, they need to be set to the same speed.
  // We use the Serial.begin() function to initialize the port
  // and set the communications speed.
  
  // The speed is measured in bits per second, also known as
  // "baud rate". 9600 is a very commonly used baud rate,
  // and will transfer about 10 characters per second.
  
  Serial.begin(9600);
}


void loop()
{

  // We'll declare three floating-point variables
  // (We can declare multiple variables of the same type on one line:)

  float voltage;
  int deg;

  // First we'll measure the voltage at the analog pin. Normally
  // we'd use analogRead(), which returns a number from 0 to 1023.
  // Here we've written a function (further down) called
  // getVoltage() that returns the true voltage (0 to 5 Volts)
  // present on an analog input pin.

  voltage = getVoltage(temperaturePin);
  
  // Now we'll convert the voltage to degrees Celsius.
  // This formula comes from the temperature sensor datasheet:

  deg = (voltage - 0.5) * 100.0;
  
  // Now we'll use the serial port to print these values
  // to the serial monitor!

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.println(deg);

  // Split the temperature into ones and tens to use for setting appropriate LEDs:
  int onesDeg = (deg % 10 );
  int tensDeg = ((deg / 10) % 10);
  
  if (onesDeg >= 1) {
    digitalWrite(onePin, HIGH);
  } else {
    digitalWrite(onePin, LOW);
  }
  
  if (onesDeg >= 2) {
    digitalWrite(twoPin, HIGH);
  } else {
    digitalWrite(twoPin, LOW);
  }
  
  if (onesDeg >= 3) {
    digitalWrite(threePin, HIGH);
  } else {
    digitalWrite(threePin, LOW);
  }
  
  if (onesDeg >= 4) {
    digitalWrite(fourPin, HIGH);
  } else {
    digitalWrite(fourPin, LOW);
  }
  
  if (onesDeg >= 5) {
    digitalWrite(fivePin, HIGH);
  } else {
    digitalWrite(fivePin, LOW);
  }
  
  if (onesDeg >= 6) {
    digitalWrite(sixPin, HIGH);
  } else {
    digitalWrite(sixPin, LOW);
  }
  
  if (onesDeg >= 7) {
    digitalWrite(sevenPin, HIGH);
  } else {
    digitalWrite(sevenPin, LOW);
  }
  
  if (onesDeg >= 8) {
    digitalWrite(eightPin, HIGH);
  } else {
    digitalWrite(eightPin, LOW);
  }
  
  if (onesDeg >= 9) {
    digitalWrite(ninePin, HIGH);
  } else {
    digitalWrite(ninePin, LOW);
  }

  if (tensDeg >= 1) {
    digitalWrite(teensPin, HIGH);
  }
  else {
    digitalWrite(teensPin, LOW);
  }

  if (tensDeg >= 2) {
    digitalWrite(twentiesPin, HIGH);
  }
  else {
    digitalWrite(twentiesPin, LOW);
  }

  if (tensDeg >= 3) {
    digitalWrite(thirtiesPin, HIGH);
  }
  else {
    digitalWrite(thirtiesPin, LOW);
  }
   
  delay(1000); // repeat once per second (change as you wish!)
}


float getVoltage(int pin)
{
  // This function has one input parameter, the analog pin number
  // to read. You might notice that this function does not have
  // "void" in front of it; this is because it returns a floating-
  // point value, which is the true voltage on that pin (0 to 5V).
  
  // You can write your own functions that take in parameters
  // and return values. Here's how:
  
    // To take in parameters, put their type and name in the
    // parenthesis after the function name (see above). You can
    // have multiple parameters, separated with commas.
    
    // To return a value, put the type BEFORE the function name
    // (see "float", above), and use a return() statement in your code
    // to actually return the value (see below).
  
    // If you don't need to get any parameters, you can just put
    // "()" after the function name.
  
    // If you don't need to return a value, just write "void" before
    // the function name.

  // Here's the return statement for this function. We're doing
  // all the math we need to do within this statement:
  
  return (analogRead(pin) * 0.004882814);
  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value that is the true voltage
  // being read at that pin.
}

// Other things to try with this code:

//   Turn on an LED if the temperature is above or below a value.

//   Read that threshold value from a potentiometer - now you've
//   created a thermostat!

