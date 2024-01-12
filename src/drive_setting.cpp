//
//  BUTTON      ACTION
//    L1    |   Shoot & Lower to high position
//    L2    |   Lower to shooting position
//    R1    |   Outtake 
//    R2    |   Intake till stopped
//    A     |   Open right wing
//    X     |   Set PTO to chassis
//    Y     |   Open both wing
//   Left   |   Open left wing
//    Up    |   Human Player Shooting
//

#include "vex.h"
#include <all_func.h>

int sum = 0;
int move = 0;
bool btn_pressed = false;
int num_pressed = 0;
int rot_angle;

bool b_press = Controller1.ButtonB.pressing();
bool Last_b = !b_press;
bool b_switch = false;

bool R2_press = Controller1.ButtonR2.pressing();
bool Last_R2 = R2_press;
int intake_spin = 0;

bool up_press = Controller1.ButtonUp.pressing();
bool match_load = false;
bool Last_up = up_press;

bool L2_press = Controller1.ButtonL2.pressing();
bool Last_L2 = L2_press;
bool cata_drop = false;

bool L1_press = Controller1.ButtonL1.pressing();
bool Last_L1 = L1_press;
int cata_rise = 0;

bool y_press = Controller1.ButtonY.pressing();
bool Last_y = y_press;
bool both_wing = false;

bool a_press = Controller1.ButtonA.pressing();
bool Last_a = a_press;
bool right_wing = false;

bool left_press = Controller1.ButtonLeft.pressing();
bool Last_left = left_press;
bool left_wing = false;

bool Down_press = Controller1.ButtonDown.pressing();
bool Last_Down = Down_press;
int cata_hang = 0;

bool Right_press = Controller1.ButtonRight.pressing();
bool Last_Right = Right_press;
int cata_side_hang = 0;



