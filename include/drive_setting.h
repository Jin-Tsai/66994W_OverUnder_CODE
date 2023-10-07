#include "vex.h"

extern int chassis_motors;
extern int sum;
extern int move;
extern bool btn_pressed;
extern int num_pressed;
extern int rot_angle;

extern bool x_press;
extern bool Last_x;
extern bool pto_switch;

extern bool R2_press;
extern bool Last_R2;
extern bool intake_spin;

extern bool up_press;
extern bool match_load;
extern bool Last_up;

extern bool L2_press;
extern bool Last_L2;
extern bool cata_drop;

extern bool L1_press;
extern bool Last_L1;
extern int cata_rise;

extern bool y_press;
extern bool Last_y;
extern bool both_wing;

extern bool a_press;
extern bool Last_a;
extern bool right_wing;

extern bool left_press;
extern bool Last_left;
extern bool left_wing;

extern double last_time;

void controller_Down_Pressed();

void controller_X_Pressed();