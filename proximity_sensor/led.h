//This file defines the Led class to use
//Now we can have state and turn the led object on or off, or toggle it if that is preferred
//include the WProgram.h header file from Arduino so that you get their constants, like OUTPUT, HIGH, LOW

#include "WProgram.h" //include this so that we get the arduino constants (HIGH, OUTPUT, etc)

class Led {
  public:
    int pin_number; //this is an instance variable keeping the pin number for us to use anytime during this object's lifetime

    Led (int n) {      
      pin_number = n; 
      pinMode(pin_number, OUTPUT); //set the arduino pin as OUTPUT
    }
    
    void on() {
      digitalWrite(pin_number, HIGH); //send the 5V to the pin to turn it on
    }
    
    void off() {
      digitalWrite(pin_number, LOW); //send 0V to the pin to turn it off
    }
};
