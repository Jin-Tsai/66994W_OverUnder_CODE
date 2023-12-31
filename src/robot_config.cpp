#include "vex.h"
#include <robot_config.h>

// define your global instances of motors and other devices here
brain Brain; 

motor intake = motor(PORT7, ratio6_1, true);

motor cata = motor(PORT20, ratio6_1, false);

motor left_front = motor(PORT6, ratio6_1, false);
motor left_mid = motor(PORT4, ratio6_1, false);
motor left_back = motor(PORT2, ratio6_1, false);
motor right_front = motor(PORT5, ratio6_1, true);
motor right_mid = motor(PORT9, ratio6_1, true);
motor right_back = motor(PORT8, ratio6_1, true);

triport Expander = triport(PORT1);

digital_out r_wing = digital_out(Expander.G);
digital_out l_wing = digital_out(Expander.H);
digital_out front_wing = digital_out(Brain.ThreeWirePort.E);
digital_out fourbar = digital_out(Brain.ThreeWirePort.A);
digital_out intake_piston = digital_out(Expander.A);
digital_out balance = digital_out(Brain.ThreeWirePort.C);

motor_group left_base = motor_group(left_front, left_mid, left_back);
motor_group right_base = motor_group(right_front, right_mid, right_back);
motor_group chassis = motor_group(left_front, left_mid, left_back, right_front, right_mid, right_back);

// distance distance_sensor = distance(PORT9);
rotation rotation_sensor = rotation(PORT4);
inertial Inertial = inertial(PORT19);
distance distance_sensor = distance(PORT3);

potV2 auto_selector = potV2(Brain.ThreeWirePort.D);
controller Controller1 = controller(primary);