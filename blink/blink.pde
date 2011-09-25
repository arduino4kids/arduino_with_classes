//This example shows how to do the simple blink with C++ classes.
//Create a tab called led.h
//In that tab you will define the Led class
//Add the #include "led.h" in this main file, so that it is available

#include "led.h" 

Led my_led (13); //create the LED that is in the built-in pin 13

void setup() {}; //put in here anything that needs to be done on startup

void loop() {
  my_led.on();  //ask the LED to turn on
  delay(100);              // wait for a 10th of a second
  my_led.off(); //ask the LED to turn off
  delay(100);              // wait for a 10th of a second
}
