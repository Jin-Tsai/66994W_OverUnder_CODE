using namespace vex;
// define your global instances of motors and other devices here
extern brain Brain; 

extern motor intake;

extern motor cata;

extern motor left_front;
extern motor left_mid;
extern motor left_back;
extern motor right_front;
extern motor right_mid;
extern motor right_back;

extern digital_out front_wing;
extern digital_out l_wing;
extern digital_out r_wing;
extern digital_out fourbar;
extern digital_out intake_piston;
extern digital_out balance;

extern motor_group left_base;
extern motor_group right_base;
extern motor_group chassis;

// distance distance_sensor = distance(PORT9);
extern rotation rotation_sensor;
extern inertial Inertial;
extern distance distance_sensor;

extern potV2 auto_selector;
extern triport Expander;
extern controller Controller1;