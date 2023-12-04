#include "vex.h"
#include <robot_config.h>

// define your global instances of motors and other devices here
brain Brain; 

motor intake = motor(PORT11, ratio6_1, true);

motor cata = motor(PORT20, ratio36_1, true);

motor left_front = motor(PORT6, ratio6_1, false);
motor left_mid = motor(PORT5, ratio6_1, false);
motor left_back = motor(PORT2, ratio6_1, false);
motor right_front = motor(PORT7, ratio6_1, true);
motor right_mid = motor(PORT9, ratio6_1, true);
motor right_back = motor(PORT8, ratio6_1, true);

digital_out r_wing = digital_out(Brain.ThreeWirePort.F);
digital_out l_wing = digital_out(Brain.ThreeWirePort.C);
digital_out front_wing = digital_out(Brain.ThreeWirePort.E);
digital_out l_rise = digital_out(Brain.ThreeWirePort.D);
digital_out r_rise = digital_out(Brain.ThreeWirePort.G);
digital_out loading = digital_out(Brain.ThreeWirePort.B);
digital_out intake_piston = digital_out(Brain.ThreeWirePort.H);

motor_group left_base = motor_group(left_front, left_mid, left_back);
motor_group right_base = motor_group(right_front, right_mid, right_back);
motor_group chassis = motor_group(left_front, left_mid, left_back, right_front, right_mid, right_back);

// distance distance_sensor = distance(PORT9);
rotation rotation_sensor = rotation(PORT3);
inertial Inertial = inertial(PORT14);
triport Expander = triport(PORT10);
potV2 auto_selector = potV2(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);