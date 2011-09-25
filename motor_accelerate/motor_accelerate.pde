  //This example uses the wiring for a motor on analog pin 9;
  
  //to connect to a serial terminal:
  //if you are on a mac, you can use the screen program
  //$ screen /dev/cu.usbserial*  or screen /dev/tty.usbserial depending on your machine
  
  //then press the i to accelerate
  //press the k to decelerate 
  //press space bar to come to complete stop
  
  #include "serial_port.h"
  #include "tiny_motor.h"
  
  SerialPort serial;
  TinyMotor motor(9);
  
  void setup() {
    serial.open_port();
  }
  
  void loop() {
    motor.update(serial);
    delay(10);
  }
  

