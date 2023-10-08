using namespace vex;
// define your global instances of motors and other devices here
extern brain Brain; 

extern motor LeftTopMotor;
extern motor RightTopMotor;
extern motor LeftBottomMotor;
extern motor RightBottomMotor;

extern motor intake;

extern motor left_front;
extern motor left_back;
extern motor right_front;
extern motor right_back;

extern digital_out r_wing;
extern digital_out l_wing;
extern digital_out pto;
extern digital_out balance;

extern motor_group left_base;
extern motor_group right_base;
extern motor_group chassis;
extern motor_group left_seven_base;
extern motor_group right_seven_base;
extern motor_group pto_cata;

// distance distance_sensor = distance(PORT9);
extern rotation rotation_sensor;
extern inertial Inertial;

extern controller Controller1;