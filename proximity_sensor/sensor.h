
#include "WProgram.h"

class Sensor {
  
  public:
  
  int pin_number;
  long duration, inches;
  
  Sensor(int n) {
    pin_number = n;
  }
  
  void send_receive_ping() {
    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(pin_number, OUTPUT);
    digitalWrite(pin_number, LOW);
    delayMicroseconds(2);
    digitalWrite(pin_number, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin_number, LOW);
    
    // The same pin is used to read the signal from the PING))): a HIGH
    // pulse whose duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(pin_number, INPUT);
    duration = pulseIn(pin_number, HIGH);
  }
  
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  long get_distance() {
    send_receive_ping();
    return duration / 74 / 2;;
  }
  
};

