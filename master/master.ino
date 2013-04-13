// Master code for uber tetris
//
// This sketch turns the Arduino into a serial-to-SPI link.
// using the following arduino pins:
//
// pin name:    not-mega:         mega(1280 and 2560)
// slave reset: 10:               53 
// MOSI:        11:               51 
// MISO:        12:               50 
// SCK:         13:               52 

#include <SPI.h>

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  // initialize SPI:
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
}

void send_spi_command() {
  uint8_t c;
 
  c = Serial.read();
  SPI.transfer(c);
}

void test_loop(void) {
  SPI.transfer(0x55);
  delay(10000);
}

// the loop routine runs over and over again forever:
void loop() {
  
  test_loop();
  
  // if (Serial.available()) {
  //  send_spi_command(); 
  // }
}

