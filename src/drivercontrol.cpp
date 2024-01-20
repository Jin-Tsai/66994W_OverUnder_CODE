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
    

    //L2 R1 R2 CONTROLLER CODE===================

    L2_press = Controller1.ButtonL2.pressing();
    
    if(L2_press && !Last_L2){
      cata_drop = !cata_drop;
    }
    Last_L2 = L2_press;

    R2_press = Controller1.ButtonR2.pressing();
    
    if(R2_press && !Last_R2){
      intake_spin = !intake_spin;
    }
    Last_R2 = R2_press;

    L1_press = Controller1.ButtonL1.pressing();
    
    if(L1_press && !Last_L1){
      cata_side_hang = !cata_side_hang;
    }
    Last_L1 = L1_press;

    if((cata_side_hang == true)){
      if((intake_spin == true)&&(intake.velocity(rpm)>0)){
        intake_spin = false;
      }
      intake.spin(reverse, 600, rpm);
      front_wing.set(true);
      intake_piston.set(true);
    }
    else if((cata_side_hang == false)){
      front_wing.set(false);
      intake_piston.set(false);
    }
    else if((intake_spin == false)&&(Controller1.ButtonR1.pressing()==false)&&(cata_side_hang == false)){
      intake.stop(coast);
    }
    // else if((intake_spin == false)&&(cata_side_hang == false)){
    //   intake.stop(coast);
    // }

    if((cata_drop == true)){
      // PID_adjust(530, 2.2, 0.7, 2.0);
      // if((Inertial.heading()<90)or(Inertial.heading()>270)){
        cata.spin(fwd, speed_volt, volt);//10.2
      // }
      // else{
        // cata.spin(reverse, speed_volt, volt);//10.2
      // }
    }
    else if((cata_drop == false)){
      // intake_spin = false;
      cata.stop(coast);
    }
    if((intake_spin == true)){
      if((cata_side_hang == true)&&(intake.velocity(rpm)<0)){
        cata_side_hang = false;
      }
      if((cata_drop == true)){
        intake.spin(fwd, 12, volt);
      }
      else if((intake_spin == true)&&(distance_sensor.objectDistance(mm)>55)){
        intake.spin(fwd, 12 , volt);
        wait(5, msec);
      }
      else if((intake_spin == true)&&(distance_sensor.objectDistance(mm)<55)){
        intake_spin = false;
        intake.stop(hold);
      }
    }
    else if((Controller1.ButtonR1.pressing())){
      intake.spin(reverse, 12, volt);
      wait(5, msec);
      intake_spin = false;
    }
    else if((intake_spin == false)&&(Controller1.ButtonR1.pressing()==false)&&(cata_side_hang == false)){
      intake.stop(coast);
    }
    // else if((intake_spin == false)&&(cata_rise == 0)&&(cata_side_hang == false)){
    //   intake.stop(coast);
    // }

    // if((Controller1.ButtonR1.pressing()==true)){
    //   speed_slow = 0.5;
    // }
    // else{
    //   speed_slow = 1;
    // }

    // Right CONTROLLER CODE============

    b_press = Controller1.ButtonB.pressing();
    
    if(b_press && !Last_b){
      b_switch = !b_switch;
    }
    Last_b = b_press;

    if((b_switch == true)){
      intake_piston.set(true);
    }
    else if((b_switch == false)){
      intake_piston.set(false);
    }


    //L1 CONTROLLER CODE================

    // L1_press = Controller1.ButtonL1.pressing();
    
    // if(L1_press && !Last_L1){
    //   cata_rise = 1;
    // }
    // Last_L1 = L1_press;

    // if((cata_rise == 1)&&(cata_rot>45)){
    //   cata.spin(reverse, 200, rpm);
    //   // wait(200, msec);
    // }
    // else if((cata_rise == 1)&&(cata_rot<15)){
    //   // cata.stop(coast);
    //   cata_rise = 2;
    // }
    // else if((cata_rise == 2)&&(cata_rot<30)){
    //   cata.spin(reverse, 200, rpm);
    // }
    // else if((cata_rise == 2)&&(cata_rot>45)){
    //   cata.stop(coast);
    //   cata_rise = 0;
    //   // Controller1.rumble("*-*");
    // }

    //CATA HANG
    Down_press = Controller1.ButtonDown.pressing();
    
    if(Down_press && !Last_Down){
      match_load = !match_load;
    }
    Last_Down = Down_press;

    if((match_load == true)){
      fourbar.set(true);
      // balance.set(true);
    }
    if((match_load == false)){
      fourbar.set(false);
      // balance.set(false);
      // intake_piston.set(true);
    }
    //CATA SIDE HANG

    Right_press = Controller1.ButtonRight.pressing();
    
    if(Right_press && !Last_Right){
      cata_rise = !cata_rise;
    }
    Last_Right = Right_press;

    if((cata_rise == true)){
      balance.set(true);
    }
    if((cata_rise == false)){
      balance.set(false);
    }
    
    //STOP CATA===================

    // if((match_load == false)&&(cata_rise==0)&&(cata_drop == false)&&(cata_hang == 0)){
    //   cata.stop(coast);
    // }
    // Controller1.Screen.setCursor(1,1);
    // Controller1.Screen.print(cata_rise);
    // Controller1.Screen.print("   ");
    // Controller1.Screen.print(rotation_sensor.angle());


    //LEFT CONTROLLER_LEFT WING============

    left_press = Controller1.ButtonLeft.pressing();

    if(left_press && !Last_left){
      left_wing = !left_wing;
    }
    Last_left = left_press;

    if(left_wing == true){
      l_wing.set(true);
    }
    else if((left_wing == false)&&(both_wing == false)){
      l_wing.set(false);
    }

    //A CONTROLLER_RIGHT WING======

    a_press = Controller1.ButtonA.pressing();

    if(a_press && !Last_a){
      right_wing = !right_wing;
    }
    Last_a = a_press;

    if(right_wing == true){
      r_wing.set(true);
    }
    else if((right_wing == false)&&(both_wing == false)){
      r_wing.set(false);
    }

    //Y CONTROLLER_BOTH WING================

    y_press = Controller1.ButtonY.pressing();

    if(y_press && !Last_y){
      both_wing = !both_wing;
    }
    Last_y = y_press;

    if(both_wing == true){
      l_wing.set(true);
      r_wing.set(true);
    }
    else if((both_wing == false)&&(left_wing == false)&&(right_wing == false)){
      l_wing.set(false);
      r_wing.set(false);
    }

    //===================

    // Brain.Screen.setCursor(1,1);
    // Brain.Screen.print("cata temp: %.2f ",cata.temperature(celsius));
    // Brain.Screen.newLine();
    // Brain.Screen.print("intake temp: %.2f ",intake.temperature(celsius));
    // Brain.Screen.newLine();
    // Brain.Screen.print("LFront temp: %.2f ",left_front.temperature(celsius));
    // Brain.Screen.newLine();
    // Brain.Screen.print("LMid temp: %.2f ",left_mid.temperature(celsius));
    // Brain.Screen.newLine();
    // Brain.Screen.print("LBack temp: %.2f ",left_back.temperature(celsius));
    // Brain.Screen.newLine();
    // Brain.Screen.print("RFront temp: %.2f ",right_front.temperature(celsius));
    // Brain.Screen.newLine();
    // Brain.Screen.print("RMid temp: %.2f ",right_mid.temperature(celsius));
    // Brain.Screen.newLine();
    // Brain.Screen.print("RBack temp: %.2f ",right_back.temperature(celsius));
    // // Brain.Screen.newLine();
    // // Brain.Screen.print("Distance: %.2f", distance_sensor.objectDistance(mm));
    // Brain.Screen.newLine();
    // Brain.Screen.print("Rotarion: %.2f", rotation_sensor.angle());
    // Brain.Screen.newLine();
    // Brain.Screen.print("Rotarion: %.2f", intake.torque());

    wait(5, msec);
  }
}