#include "vex.h"
#include <robot_config.h>

// define your global instances of motors and other devices here
brain Brain; 

motor intake = motor(PORT17, ratio6_1, true);

motor cata = motor(PORT15, ratio36_1, true);

motor left_front = motor(PORT19, ratio6_1, false);
motor left_mid = motor(PORT16, ratio6_1, false);
motor left_back = motor(PORT11, ratio6_1, false);
motor right_front = motor(PORT20, ratio6_1, true);
motor right_mid = motor(PORT18, ratio6_1, true);
motor right_back = motor(PORT1, ratio6_1, true);

digital_out r_wing = digital_out(Brain.ThreeWirePort.A);
digital_out l_wing = digital_out(Brain.ThreeWirePort.D);

motor_group left_base = motor_group(left_front, left_mid, left_back);
motor_group right_base = motor_group(right_front, right_mid, right_back);
motor_group chassis = motor_group(left_front, left_mid, left_back, right_front, right_mid, right_back);

// distance distance_sensor = distance(PORT9);
rotation rotation_sensor = rotation(PORT3);
inertial Inertial = inertial(PORT14);
triport Expander = triport(PORT10);
potV2 auto_selector = potV2(Brain.ThreeWirePort.F);
controller Controller1 = controller(primary);