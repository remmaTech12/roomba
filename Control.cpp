#include "Arduino.h"
#include "Control.h"

Control::Control()
{
}

void Control::init() {
  pinMode(MOTOR_L_PWM,OUTPUT);
  pinMode(DIR1A_L,OUTPUT);
  pinMode(DIR2A_L,OUTPUT);
  pinMode(MOTOR_R_PWM,OUTPUT);
  pinMode(DIR4A_L,OUTPUT);
  pinMode(DIR3A_L,OUTPUT);
}

void Control::left_wheel_forth (void) {
   digitalWrite(MOTOR_L_PWM,180); // enable on
   digitalWrite(DIR1A_L,HIGH); // one way
   digitalWrite(DIR2A_L,LOW);
}

void Control::left_wheel_back(void) {
  digitalWrite(MOTOR_L_PWM, 180);  // disable
  digitalWrite(DIR1A_L, LOW);      // one way
  digitalWrite(DIR2A_L, HIGH);
}

void Control::right_wheel_forth (void) {
  digitalWrite(MOTOR_R_PWM,180); // enable on
  digitalWrite(DIR4A_L,HIGH); // one way
  digitalWrite(DIR3A_L,LOW);
}

void Control::right_wheel_back (void) {
  digitalWrite(MOTOR_R_PWM, 180);  // disable
  digitalWrite(DIR4A_L, LOW);      // one way
  digitalWrite(DIR3A_L, HIGH);
}

void Control::turn_right(void) {
  left_wheel_forth();
  right_wheel_back();
  delay(2000);
}

void Control::turn_left(void) {
  right_wheel_forth();
  left_wheel_back();
  delay(2000);
}

void Control::move_forth(void) {
  left_wheel_forth();
  right_wheel_forth();
  delay(2000);
}

void Control::move_back(void) {
  left_wheel_back();
  right_wheel_back();
  delay(2000);
}

void Control::curve_infrontof_wall(long distance) {
  if (distance < 13) {
    turn_left();
  } else{
    move_forth();
  }
}

void Control::test_move_back_and_force(void) {
  move_back();
  delay(2000);
  
  move_forth();
  delay(2000);
}

void Control::test_move_back_and_force_with_sensor(long distance) {
  if (distance < 25) {
    move_back();
  } else{
    move_forth();
  }
}