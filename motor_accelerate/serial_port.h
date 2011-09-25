//We create a class to wrap the Serial functionality, plus we add
//methods that we want in this class, tailored to the specific problem we want to address

#include "WProgram.h"

class SerialPort {
  public:
    int baud_rate;
    
    SerialPort() {
      baud_rate = 9600; //seems like every connection I see uses 9600 baud rate so we will use it here.
    }
    
    void open_port() {
      Serial.begin(baud_rate); //this is a method to open the serial port. There is probably a call to close it too.
    }
    
    void close_port() {
      Serial.end();
    }
    
    boolean is_receiving_input() {
      return (Serial.available() > 0);
    }
    
    int letter_pressed() {
      int letter = 0;
      if(is_receiving_input()){
        letter = Serial.read();
      }
      return letter;
    }
    
    boolean is_letter_pressed(int letter) {
      return(letter_pressed() == letter);
    }
    
   void print_string(String str) {
     Serial.println(str);
   }
};

