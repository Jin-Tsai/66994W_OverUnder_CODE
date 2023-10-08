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

int chassis_motors = 4;
int sum = 0;
int move = 0;
bool btn_pressed = false;
int num_pressed = 0;
int rot_angle;

bool x_press = Controller1.ButtonX.pressing();
bool Last_x = !x_press;
bool pto_switch = false;

bool R2_press = Controller1.ButtonR2.pressing();
bool Last_R2 = R2_press;
bool intake_spin = false;

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

double last_time;

void controller_Down_Pressed(){
  if(Controller1.ButtonDown.pressing()){
    pto.set(true);
    balance.set(true);
  }
}

void controller_X_Pressed(){
  while(1){
    x_press = Controller1.ButtonX.pressing();
      
    if(x_press && !Last_x){
      pto_switch = true;
    }
    Last_x = x_press;

    if(pto_switch == true){
      pto.set(true);
      chassis_motors = 7;
      pto_switch = false;
    }
  }

}