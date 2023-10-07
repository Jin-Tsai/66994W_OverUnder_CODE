/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       yjtsa                                                     */
/*    Created:      8/24/2023, 5:50:07 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include <all_func.h>

using namespace vex;

// A global instance of competition
competition Competition;

void inertial_calibate() {
  Inertial.calibrate();
  while (Inertial.isCalibrating()) {
    wait(10, msec);
  }
  Controller1.rumble("*-*");
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  inertial_calibate();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

int task1(){
  pto_cata.spin(fwd, 200, rpm);
  wait(500, msec);
  pto_cata.spin(reverse, 200, rpm);
  wait(300, msec);
  pto_cata.stop(coast);
  while(rotation_sensor.angle()<85){
    pto_cata.spin(reverse, 200, rpm);
  }
  pto_cata.stop(coast);
  return 0;
}

void autonomous(void) {
  same_side_15();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  driver_control();
  
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("GyroHeading: %.2f ",Inertial.heading());
    wait(100, msec);
  }
}