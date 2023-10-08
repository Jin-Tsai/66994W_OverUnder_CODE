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

// Pre AUTON

void pre_auton(void) {
  inertial_calibate();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

// Autonomous Skills

void autonomous(void) {
  same_side_awp();
}

//Driver Control

void usercontrol(void) {
  // User control code here, inside the loop
  driver_control();
  
}


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