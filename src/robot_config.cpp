#include "vex.h"
#include <robot_config.h>

// define your global instances of motors and other devices here
brain Brain; 

motor LeftTopMotor = motor(PORT12, ratio18_1, false);
motor RightTopMotor = motor(PORT15, ratio18_1, true);
motor LeftBottomMotor = motor(PORT10, ratio18_1, true);
motor RightBottomMotor = motor(PORT1, ratio18_1, false);

motor intake = motor(PORT17, ratio6_1, true);

motor left_front = motor(PORT19, ratio6_1, false);
motor left_back = motor(PORT16, ratio6_1, false);
motor right_front = motor(PORT20, ratio6_1, true);
motor right_back = motor(PORT18, ratio6_1, true);

digital_out r_wing = digital_out(Brain.ThreeWirePort.A);
digital_out l_wing = digital_out(Brain.ThreeWirePort.H);
digital_out pto = digital_out(Brain.ThreeWirePort.G);
digital_out balance = digital_out(Brain.ThreeWirePort.B);

motor_group left_base = motor_group(left_front, left_back);
motor_group right_base = motor_group(right_front, right_back);
motor_group chassis = motor_group(left_front, left_back, right_front, right_back);
motor_group left_seven_base = motor_group(left_front, left_back, LeftTopMotor, LeftBottomMotor);
motor_group right_seven_base = motor_group(right_front, right_back, RightTopMotor, RightBottomMotor);
motor_group pto_cata = motor_group(LeftTopMotor, LeftBottomMotor, RightTopMotor, RightBottomMotor);

// distance distance_sensor = distance(PORT9);
rotation rotation_sensor = rotation(PORT3);
inertial Inertial = inertial(PORT14);

controller Controller1 = controller(primary);