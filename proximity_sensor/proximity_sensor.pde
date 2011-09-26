//This program incorporates the PING))) proximity sensor
//If the sensor gets placed less than 5 inches from a wall or any object
//the built in LED will turn on
//otherwise the LED will turn off

#include "sensor.h"
#include "led.h"

Sensor my_sensor(7);
Led built_in_led(13);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  long distance = my_sensor.get_distance();
  Serial.println(distance);
  
  if (distance < 5) {
    built_in_led.on();
  }
  else {
    built_in_led.off();
  }
  
}

