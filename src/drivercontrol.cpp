#include "vex.h"
#include <all_func.h>

void driver_control(){
  Controller1.ButtonDown.pressed(controller_Down_Pressed);
  wait(15,msec);

  Brain.Timer.clear();

  while(true){

    if(chassis_motors==6){
      left_base.setVelocity(-(Controller1.Axis3.position()+Controller1.Axis1.position()+move), percent);
      right_base.setVelocity(-(Controller1.Axis3.position()-Controller1.Axis1.position()+move), percent);
    }
    
    if(abs(Controller1.Axis3.position())>10){
      left_base.setStopping(coast);
      right_base.setStopping(coast);
    }
    if(abs(Controller1.Axis1.position())>10){
      left_base.setStopping(brake);
      right_base.setStopping(brake);
    }
    if(chassis_motors==6){
      left_base.spin(forward);
      right_base.spin(forward);
    }

    //R2 CONTROLLER CODE==============

    R2_press = Controller1.ButtonR2.pressing();
    
    if(R2_press && !Last_R2){
      intake_spin = !intake_spin;
    }
    Last_R2 = R2_press;

    if((Controller1.ButtonR1.pressing())){
      intake.spin(fwd, 600, rpm);
      wait(5, msec);
    }
    else if((intake_spin == true)&&(intake.torque()<0.3)){
      intake.spin(reverse, 600 , rpm);
      wait(5, msec);
    }
    else if((intake.torque()>=0.3)&&(last_time == 0.0)){
      last_time = Brain.Timer.time();
    }
    else if((intake.torque()>=0.3)&&((Brain.Timer.time(msec)-last_time)>700)){
      intake_spin = false;
      intake.stop(brake);
      last_time = 0.0;
    }
    else if((intake_spin == false)){
      intake.stop(brake);
      last_time = 0.0;
    }

    //MATCH LOAD CODE===========================

    up_press = Controller1.ButtonUp.pressing();
    
    if(up_press && !Last_up){
      match_load = !match_load;
    }
    Last_up = up_press;

    if((match_load == true)&&(rotation_sensor.angle()>310)){
      cata.spin(reverse, 200, rpm);
    }
    else if((match_load == true)&&(rotation_sensor.angle()<310)){
      cata.stop(brake);
      cata.spin(fwd, 200, rpm);
      wait(100, msec);
      cata.stop(brake);
      wait(5, msec);
    }

    //L2 CONTROLLER CODE===================

    L2_press = Controller1.ButtonL2.pressing();
    
    if(L2_press && !Last_L2){
      cata_drop = true;
    }
    Last_L2 = L2_press;

    if((cata_drop == true)&&(rotation_sensor.angle()>295)){
      cata.spin(reverse, 200, rpm);
    }
    else if((cata_drop == true)&&(rotation_sensor.angle()<290)){
      cata.stop(coast);
      cata_drop = false;
    }

    //L1 CONTROLLER CODE================

    L1_press = Controller1.ButtonL1.pressing();
    
    if(L1_press && !Last_L1){
      cata_rise = 1;
    }
    Last_L1 = L1_press;

    if((cata_rise == 1)&&(rotation_sensor.angle()<345)){
      cata.spin(fwd, 200, rpm);
      // wait(200, msec);
      // pto_cata.stop(coast);
    }
    else if((cata_rise == 1)&&(rotation_sensor.angle()>340)){
      cata.stop(coast);
      cata_rise = 2;
    }
    else if((cata_rise == 2)&&(rotation_sensor.angle()>330)){
      cata.spin(reverse, 200, rpm);
    }
    else if((cata_rise == 2)&&(rotation_sensor.angle()<310)){
      cata.stop(coast);
      cata_rise = 0;
      // Controller1.rumble("*-*");
    }

    //STOP CATA===================

    if((match_load == false)&&(cata_rise==0)&(cata_drop == false)){
      cata.stop(coast);
    }

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

    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("cata temp: %.2f ",cata.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("intake temp: %.2f ",intake.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("LFront temp: %.2f ",left_front.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("LMid temp: %.2f ",left_mid.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("LBack temp: %.2f ",left_back.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("RFront temp: %.2f ",right_front.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("RMid temp: %.2f ",right_mid.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("RBack temp: %.2f ",right_back.temperature(celsius));
    // Brain.Screen.newLine();
    // Brain.Screen.print("Distance: %.2f", distance_sensor.objectDistance(mm));
    Brain.Screen.newLine();
    Brain.Screen.print("Rotarion: %.2f", rotation_sensor.angle());
    Brain.Screen.newLine();
    Brain.Screen.print("Rotarion: %.2f", intake.torque());

    wait(5, msec);
  }
}