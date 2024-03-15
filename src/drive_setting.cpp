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

bool R2_press = Controller1.ButtonR2.pressing();
bool Last_R2 = R2_press;
bool R2_intake_spin = false;

bool Down_press = Controller1.ButtonDown.pressing();
bool match_load = false;
bool Last_Down = Down_press;

bool L2_press = Controller1.ButtonL2.pressing();
bool Last_L2 = L2_press;
bool L2_right_front_wing = false;

bool L1_press = Controller1.ButtonL1.pressing();
bool Last_L1 = L1_press;
bool L1_left_front_wing = false;

bool y_press = Controller1.ButtonY.pressing();
bool Last_y = y_press;
bool both_wing = false;

bool a_press = Controller1.ButtonA.pressing();
bool Last_a = a_press;
bool a_right_back_wing = false;

bool left_press = Controller1.ButtonLeft.pressing();
bool Last_left = left_press;
bool left_back_wing = false;

bool Right_press = Controller1.ButtonRight.pressing();
bool Last_Right = Right_press;
bool side_hang = false;

bool B_press = Controller1.ButtonB.pressing();
bool Last_B = B_press;
bool B_matchload = false;