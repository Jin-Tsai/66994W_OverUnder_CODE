#include "vex.h"
#include <robot_config.h>

// define your global instances of motors and other devices here
brain Brain; 

motor intake = motor(PORT2, ratio6_1, true);

motor cata_left = motor(PORT1, ratio18_1, false);
motor cata_right = motor(PORT10, ratio18_1, true);

motor left_front = motor(PORT11, ratio6_1, false);
motor left_mid = motor(PORT12, ratio6_1, true);
motor left_back = motor(PORT13, ratio6_1, false);
motor right_front = motor(PORT18, ratio6_1, false);
motor right_mid = motor(PORT19, ratio6_1, true);
motor right_back = motor(PORT20, ratio6_1, true);

triport Expander = triport(PORT8);

digital_out r_back = digital_out(Brain.ThreeWirePort.G);
digital_out l_back = digital_out(Expander.E);
digital_out r_front = digital_out(Expander.A);
digital_out l_front = digital_out(Expander.G);
digital_out side_hang_piston = digital_out(Expander.F);
digital_out front_hang = digital_out(Brain.ThreeWirePort.H);

motor_group left_base = motor_group(left_front, left_mid, left_back);
motor_group right_base = motor_group(right_front, right_mid, right_back);
motor_group chassis = motor_group(left_front, left_mid, left_back, right_front, right_mid, right_back);
motor_group cata = motor_group(cata_left, cata_right);

// distance distance_sensor = distance(PORT9);
rotation rotation_sensor = rotation(PORT4);
inertial Inertial = inertial(PORT9);
distance distance_sensor = distance(PORT7);

potV2 auto_selector = potV2(Expander.H);
controller Controller1 = controller(primary);