#ifndef Control_h
#define Control_h

#define MOTOR_L_PWM 5
#define DIR1A_L 3
#define DIR2A_L 4
#define MOTOR_R_PWM 10
#define DIR4A_L 8
#define DIR3A_L 9

class Control
{
public:
  Control();
  void init();
  void test_move_back_and_force();
  void test_move_back_and_force_with_sensor(long distance);

private:
};

#endif