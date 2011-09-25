#include "WProgram.h"

class SerialPort {
  public:
    int baud_rate;
    SerialPort() {
    }
    
    void begin(int rate) {
      baud_rate = rate;
      Serial.begin(baud_rate);
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
    
   
};

