/*
  Slave code for ÜberTetris controller
 */

#include "pins_arduino.h"
#include <SPI.h>

// Pin to LED connection
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
  delay(10);
  led_off(led);
}

void wait(int d) {
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
  delay(1000);
  led_off(red);
  led_off(green);  
  led_off(blue);

  // FIXME initialize SPI
}

void led_red(uint8_t mag) {
  if (mag > 127) {
    led_on(red);
  } else {
    led_off(red);
  }
}

void led_green(uint8_t mag) {
  if (mag > 127) {
    led_on(green);
  } else {
    led_off(green);
  }
}

void led_blue(uint8_t mag) {
  if (mag > 127) {
    led_on(blue);
  } else {
    led_off(blue);
  }
}

typedef struct rgb {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} color_t;

color_t color;

// coordinates of this pixel
uint8_t x=0;
uint8_t y=0;

void put_out(uint8_t red, uint8_t green, uint8_t blue){
  led_red(red);
  led_green(green);
  led_blue(blue);
}

void listen_command(uint8_t x, uint8_t y){
  // FIXME .. wait for a command
  
  int r = random(255);
  int g = random(255);
  int b = random(255);

  put_out(r, g, b);
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  listen_command(x,y);
}

