  #include "WProgram.h" //include this so that we get the arduino constants (HIGH, OUTPUT, etc)
  
  class TinyMotor {
    public:
    
    int pin_number;
    int motor_speed;

    TinyMotor (int n) {
      pin_number = n;
      motor_speed = 255; //speed is a number between 0 and 255
      pinMode(pin_number, OUTPUT);
    }
    
    void update(SerialPort serial) {
      int letter = serial.letter_pressed();
  
      if(letter == int('i')) { //accelerate motor
        accelerate();
      }
      else if (letter == int('k')){ //delerate motor
        decelerate();
      }
      else if (letter == 32) { //space bar stops the motor
        motor_speed = 0;
      }
      serial.print_string(motor_speed);
      analogWrite(pin_number, motor_speed); //send the appropriate voltage to the motor
    }

    
    void change_speed(int increment_value) {
      motor_speed += increment_value; //change the increment value
      
      //make sure the new value is not beyond the limits
      if (motor_speed < 0) {
        motor_speed = 0;
      }
      if (motor_speed > 255) {
        motor_speed = 255;
      }
    }
    
    void accelerate() {
      change_speed(+50);
    }
    
    void decelerate() {
      change_speed(-50);
    }
    
  };
