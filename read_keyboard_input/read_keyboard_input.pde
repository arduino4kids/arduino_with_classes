//This is a sample program to show how we can read the input of the keyboard
//via the serial port

#include "serial_port.h"

SerialPort serial;

void setup() {           
  serial.open_port();
}

void loop() {
  int letter;
  letter = serial.letter_pressed();
  
  if(letter == int('A')) {
    serial.print_string("letter A pressed");
  }
  else if (letter == 0) {
    //nothing was read
  }
  else if (letter == int('q')){ //if they press the lowercase q, we close the serial connection
    serial.print_string("Goodbye");
    serial.close_port();
  }
  else {
    serial.print_string(String(letter)); //if they press any other keyboard letter, show the ASCII character of what was pressed
  }

}
