/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 3 has the red LED on it
int red = 3;
int green = 4;
int blue = 0;

void led_on(int led) {
  digitalWrite(led, HIGH);
}

void led_off(int led) {
  digitalWrite(led, LOW);
}

void flick(int led) {
  led_on(led);
  delay(100);
  led_off(led);
}

void real_delay(int d) {
  delay(d/8);
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the pins as an output.
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  led_on(red);
  led_on(green);
  led_on(blue);
  delay(4000);
  led_off(red);
  led_off(green);
  led_off(blue);
}

// the loop routine runs over and over again forever:
void loop() {
  flick(red);
  flick(green);
  flick(blue);
}
