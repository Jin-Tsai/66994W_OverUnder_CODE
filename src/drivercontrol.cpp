#include "vex.h"
#include <all_func.h>

// double gyro_auto = 0;

// double last_time;

// double y_mapping(double input, double max_in, double min_in)
// {
//   double output = 240 + ((input - min_in) * (-240)) / (max_in - min_in);
//   return output;
// }

// double last_y_velocity = 0;
// int count = 1;

// int display_PID()
// {
//   y_velocity = y_mapping(cata.velocity(rpm), 800, 0);

//   Brain.Screen.drawLine(count - 1, last_y_velocity, count, y_velocity);
//   if (count > 480)
//   {
//     count = 1;
//     Brain.Screen.clearScreen();
//   }
//   last_y_velocity = y_velocity;
//   count++;

//   return 0;
// }

// double error_pid;
// double integral_pid;
// double derivative_pid;
// double base_rpm = 530;
// double last_error = 0;
// double speed_rpm = error_pid*kp+integral_pid*ki+derivative_pid*kd+base_rpm;

// void PID_adjust(double target_rpm, double kp, double ki, double kd){

//   // while(1){

//   error_pid = abs(target_rpm-cata.velocity(rpm));
//   integral_pid = integral_pid + error_pid;
//   derivative_pid = error_pid + last_error;

//   if((error_pid<8)&&(error_pid>4)){
//     speed_rpm = error_pid*kp+integral_pid*ki+derivative_pid*kd+base_rpm;
//   }
//   else{
//     speed_rpm = error_pid*kp+derivative_pid*kd+base_rpm;
//   }
//   double speed_volt = (speed_rpm/620)*12;
//   if(cata.velocity(rpm)<400){
//     cata.spin(fwd, 12, volt);
//   }
//   else{
//     cata.spin(fwd, speed_volt, volt);
//   }

//   last_error = error_pid;
//   // }

// }

void driver_control(){

  Brain.Timer.clear();
  double cata_rot=0;
  double speed_slow=1;

  while(true){

    left_base.setVelocity((-(Controller1.Axis3.position()+Controller1.Axis1.position()+move))*speed_slow, percent);
    right_base.setVelocity((-(Controller1.Axis3.position()-Controller1.Axis1.position()+move))*speed_slow, percent);
 
    
    if(abs(Controller1.Axis3.position())>10){
      left_base.setStopping(coast);
      right_base.setStopping(coast);
    }
    if(abs(Controller1.Axis1.position())>10){
      left_base.setStopping(brake);
      right_base.setStopping(brake);
    }

    left_base.spin(forward);
    right_base.spin(forward);

    //B catapult matchload===================

    B_press = Controller1.ButtonB.pressing();

    if(B_press && !Last_B){
      B_matchload = !B_matchload;
    }
    Last_B = B_press;

    if((B_matchload == true)){
      cata.spin(fwd, 12, volt);
    }
    else if(B_matchload == false){
      cata.stop(coast);
    }
    

    //R1 R2 INTAKE CONTROLLER CODE===================

    R2_press = Controller1.ButtonR2.pressing();

    if(R2_press && !Last_R2){
      R2_intake_spin = !R2_intake_spin;
    }
    Last_R2 = R2_press;

    if((R2_intake_spin == true)){
      if((R2_intake_spin == true)&&(distance_sensor.objectDistance(mm)>55)){
        intake.spin(fwd, 12 , volt);
        wait(5, msec);
      }
      else if((R2_intake_spin == true)&&(distance_sensor.objectDistance(mm)<55)){
        R2_intake_spin = false;
        intake.stop(hold);
      }
    }
    else if((Controller1.ButtonR1.pressing())){
      intake.spin(reverse, 12, volt);
      wait(5, msec);
      R2_intake_spin = false;
    }
    else if((R2_intake_spin == false)&&(Controller1.ButtonR1.pressing()==false)){
      intake.stop(coast);
      R2_intake_spin = false;
    }

    // L1 L2 FRONT WING CONTROLLER CODE============

    L1_press = Controller1.ButtonL1.pressing();

    if(L1_press && !Last_L1){
      L1_left_front_wing = !L1_left_front_wing;
    }
    Last_L1 = L1_press;

    L2_press = Controller1.ButtonL2.pressing();

    if(L2_press && !Last_L2){
      L2_right_front_wing = !L2_right_front_wing;
    }

    Last_L2 = L2_press;

    if((L1_left_front_wing == true)){
      l_front.set(true);
    }
    else if((L1_left_front_wing == false)){
      l_front.set(false);
    }

    if((L2_right_front_wing == true)){
      r_front.set(true);
    }
    else if((L2_right_front_wing == false)){
      r_front.set(false);
    }

    //CATA HANG
    Down_press = Controller1.ButtonDown.pressing();
    
    if(Down_press && !Last_Down){
      match_load = !match_load;
    }
    Last_Down = Down_press;

    if((match_load == true)){
      front_hang.set(true);
      // balance.set(true);
    }
    if((match_load == false)){
      front_hang.set(false);
      // balance.set(false);
      // intake_piston.set(true);
    }

    //CATA SIDE HANG ===========================

    Right_press = Controller1.ButtonRight.pressing();

    if(Right_press && !Last_Right){
      side_hang = !side_hang;
    }
    Last_Right = Right_press;

    if((side_hang == true)){
      side_hang_piston.set(true);
    }
    if((side_hang == false)){
      side_hang_piston.set(false);
    }


    //LEFT CONTROLLER LEFT BACK WING============

    left_press = Controller1.ButtonLeft.pressing();

    if(left_press && !Last_left){
      left_back_wing = !left_back_wing;
    }
    Last_left = left_press;

    if(left_back_wing == true){
      l_back.set(true);
    }
    else if((left_back_wing == false)&&(both_wing == false)){
      l_back.set(false);
    }

    //A CONTROLLER_RIGHT WING======

    a_press = Controller1.ButtonA.pressing();

    if(a_press && !Last_a){
      a_right_back_wing = !a_right_back_wing;
    }
    Last_a = a_press;

    if(a_right_back_wing == true){
      r_back.set(true);
    }
    else if((a_right_back_wing == false)&&(both_wing == false)){
      r_back.set(false);
    }


    //Y CONTROLLER_BOTH WING================

    y_press = Controller1.ButtonY.pressing();
    if(y_press && !Last_y){
      both_wing = !both_wing;
    }
    Last_y = y_press;
    if(both_wing == true){
      l_back.set(true);
      r_back.set(true);
    }
    else if((both_wing == false)&&(left_back_wing == false)&&(a_right_back_wing == false)){
      l_back.set(false);
      r_back.set(false);
    }

    wait(5, msec);
  }
}