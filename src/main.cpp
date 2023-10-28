#include "vex.h"
#include <all_func.h>

using namespace vex;

// A global instance of competition
competition Competition;
void inertial_calibate()
{
  Inertial.calibrate();
  while (Inertial.isCalibrating())
  {
    wait(10, msec);
  }
  Controller1.rumble("*-*");
}

// Pre AUTON
int auto_select;
bool auto_bool = true;
void pre_auton(void)
{

  inertial_calibate();
  Brain.Screen.setFont(mono60);
  while (auto_bool)
  {
    auto_select = auto_selector.value(pct);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Rotarion: %.2f", rotation_sensor.angle());
    Brain.Screen.newLine();
    Brain.Screen.print(auto_selector.value(pct));
    Brain.Screen.print("   ");
    Brain.Screen.newLine();
    switch (auto_select)
    {
    case 7 ... 16:
      Brain.Screen.print("auto_skills");
      break;
    case 17 ... 33:
      Brain.Screen.print("diif_side_awp_middle");
      break;
    default:
      Brain.Screen.print("same_side_awp");
      break;
    }
    wait(5, msec);
  }
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.setFont(mono20);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

// Autonomous Skills

void autonomous(void)
{
  Brain.Screen.clearScreen();
  Brain.Timer.clear();
  auto_bool = false;
  switch (auto_select)
  {
  case 7 ... 16:
    Brain.Screen.print("auto_skills");
    auto_skills();
    break;
  case 17 ... 33:
    Brain.Screen.print("diif_side_awp_middle");
    diff_side_awp_middle();
    break;
  default:
    Brain.Screen.print("same_side_awp");
    same_side_awp();
    break;
  }
  // test();
}

// Driver Control

void usercontrol(void)
{
  // User control code here, inside the loop
  Brain.Screen.clearScreen();
  driver_control();
}

int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("GyroHeading: %.2f ", Inertial.heading());
    Brain.Screen.newLine();
    Brain.Screen.print("Battery: %.2f ", Brain.Battery.capacity());

    Brain.Screen.newLine();
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

    if(Brain.Battery.capacity()<40){
      Controller1.rumble("*-*");
    }

    wait(100, msec);
  }
}