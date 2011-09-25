#include "serial_port.h"


SerialPort serial;

void setup() {           
  serial.begin(9600);  //Start reading the serial port that comes into the arduino, in this case from the keyboard in the computer

}

void loop() {
  if (serial.is_letter_pressed('A')) {
    Serial.println("A pressed");
  }

}
