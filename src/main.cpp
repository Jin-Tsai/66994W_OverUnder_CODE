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

// 0  darkest brown   96-06
// 13 lightest brown  07-21
// 29 green           22-38
// 46 yellow          39-55
// 63 blue            56-72
// 83 middle brown    73-95

// Pre AUTON
int auto_select;
bool auto_bool = true;
void pre_auton(void)
{

  // inertial_calibate();
  Brain.Screen.setFont(mono60);
  while (auto_bool)
  {
    auto_select = auto_selector.value(pct);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Gyro: %.2f", Inertial.angle());
    Brain.Screen.newLine();
    Brain.Screen.print(auto_selector.value(pct));
    Brain.Screen.print("   ");
    Brain.Screen.newLine();
    switch (auto_select)
    {
    case 7 ... 21:
      Brain.Screen.print("near_awp_shoot");
      break;
    case 22 ... 38:
      Brain.Screen.print("near_awp_only");
      break;
    case 39 ... 55:
      Brain.Screen.print("near_final_simple");
      break;
    case 56 ... 72:
      Brain.Screen.print("far_6_elevation");
      break;
    case 73 ... 95:
      Brain.Screen.print("auto_skills");
      break;
    default:
      Brain.Screen.print("near_stop_middle");
      break;
    }
    Brain.Screen.print("              ");
    wait(5, msec);
  }
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.setFont(mono20);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

// Autonomous Skills

void autonomous(void)
{
  auto_bool = false;
  Brain.Screen.clearScreen();
  Brain.Timer.clear();
  // auto_skills();
  switch (auto_select)
  {
  case 7 ... 21:
    // Brain.Screen.print("near_awp_shoot");
    near_awp_shoot();
    break;
  case 22 ... 38:
    // Brain.Screen.print("near_awp_only");
    near_awp_only();
    break;
  case 39 ... 55:
    // Brain.Screen.print("near_final_simple");
    near_final_simple();
    break;
  case 56 ... 72:
    // Brain.Screen.print("far_6_elevation");
    far_6_elevation();
    break;
  case 73 ... 95:
    // Brain.Screen.print("auto_skills");
    auto_skills();
    break;
  default:
    // Brain.Screen.print("near_stop_middle");
    break;
  }
}

// Driver Control

void usercontrol(void)
{
  auto_bool = false;
  // User control code here, inside the loop
  Brain.Screen.clearScreen();
  driver_control();
}

double last_time;

double y_mapping(double input, double max_in, double min_in)
{
  double output = 240 + ((input - min_in) * (-240)) / (max_in - min_in);
  return output;
}

double last_y_velocity = 0;
int count = 1;

int display_PID()
{
  Brain.Screen.drawLine(0, y_mapping(530,800,0), 480, y_mapping(530,800,0));

    double y_velocity = y_mapping(cata.velocity(rpm), 800, 0);

    Brain.Screen.drawLine(count - 1, last_y_velocity, count, y_velocity);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("rpm: %.2f ",cata.velocity(rpm));
    if (count > 480)
    {
      count = 1;
      Brain.Screen.clearScreen();
    }
    last_y_velocity = y_velocity;
    count++;

  return 0;
}

int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  Brain.Screen.clearScreen();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    // PID_adjust(530, 2.0, 0.4, 0.7);//2.0 0.4 0.7
    // // cata.spin(fwd, 10.2, volt);
    // display_PID();
    
    wait(5, msec);

    // Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("GyroHeading: %.2f ", Inertial.heading());
    Brain.Screen.newLine();
    Brain.Screen.print("Battery: %d pct", Brain.Battery.capacity(pct));

    Brain.Screen.newLine();
    Brain.Screen.print("flywheel temp: %.0f˙C",cata.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("intake temp: %.0f˙C",intake.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("LFront temp: %.0f˙C",left_front.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("LMid temp: %.0f˙C",left_mid.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("LBack temp: %.0f˙C",left_back.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("RFront temp: %.0f˙C",right_front.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("RMid temp: %.0f˙C",right_mid.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("RBack temp: %.0f˙C",right_back.temperature(celsius));
    Brain.Screen.newLine();
    Brain.Screen.print("Distance: %.1f", distance_sensor.objectDistance(mm));

    if(Brain.Battery.capacity()<40){
      Controller1.rumble("*-*");
    }
  }
}