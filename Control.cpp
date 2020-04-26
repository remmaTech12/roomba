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

void Control::test_move_back_and_force(void) {
  digitalWrite(MOTOR_L_PWM,180); // disable
  digitalWrite(DIR1A_L,LOW); // one way
  digitalWrite(DIR2A_L,HIGH);
  digitalWrite(MOTOR_R_PWM,180); // disable
  digitalWrite(DIR4A_L,LOW); // one way
  digitalWrite(DIR3A_L,HIGH);
  delay(2000);
  
  digitalWrite(MOTOR_L_PWM,180); // enable on
  digitalWrite(DIR1A_L,HIGH); // one way
  digitalWrite(DIR2A_L,LOW);
  digitalWrite(MOTOR_R_PWM,180); // enable on
  digitalWrite(DIR4A_L,HIGH); // one way
  digitalWrite(DIR3A_L,LOW);
  delay(2000);
}

void Control::test_move_back_and_force_with_sensor(long distance) {
  if (distance < 13) {
    digitalWrite(MOTOR_L_PWM,180); // disable
    digitalWrite(DIR1A_L,LOW); // one way
    digitalWrite(DIR2A_L,HIGH);
    digitalWrite(MOTOR_R_PWM,180); // disable
    digitalWrite(DIR4A_L,LOW); // one way
    digitalWrite(DIR3A_L,HIGH);
  } else{
    digitalWrite(MOTOR_L_PWM,180); // enable on
    digitalWrite(DIR1A_L,HIGH); // one way
    digitalWrite(DIR2A_L,LOW);
    digitalWrite(MOTOR_R_PWM,180); // enable on
    digitalWrite(DIR4A_L,HIGH); // one way
    digitalWrite(DIR3A_L,LOW);
  }
}