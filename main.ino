//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/

#include "SR04.h"
#include "Control.h"
#define TRIG_PIN 12
#define ECHO_PIN 11

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
Control ctrl = Control();

void setup() {
  //---set pin direction
  ctrl.init();
  Serial.begin(9600);
  delay(500);
}

void loop() {
  long distance=sr04.Distance();
  Serial.print(distance);
  Serial.println("cm");

  ctrl.curve_infrontof_wall(distance);
  //ctrl.turn_right();
  //ctrl.turn_left();
  //ctrl.test_move_back_and_force_with_sensor(distance);
}
