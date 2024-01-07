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
    case 7 ... 16:
      Brain.Screen.print("auto_skills");
      break;
    case 17 ... 33:
      Brain.Screen.print("diif_side_awp");
      break;
    case 34 ... 60:
      Brain.Screen.print("same_side_5_qual");
      break;
    case 61 ... 76:
      Brain.Screen.print("same_side_6final");
      break;
    default:
      Brain.Screen.print("diff_side_final");
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
  auto_bool = false;
  Brain.Screen.clearScreen();
  Brain.Timer.clear();
  // auto_skills();
  switch (auto_select)
  {
  case 7 ... 16:
    // Brain.Screen.print("auto_skills");
    auto_skills_middle();
    break;
  case 17 ... 33:
    // Brain.Screen.print("diif_side_awp");
    diff_side_final_simple();
    break;
  case 34 ... 60:
    // Brain.Screen.print("same_side_5_qual");
    same_side_5final();
    break;
  case 61 ... 76:
    // Brain.Screen.print("same_side_6final");
    same_side_final();
    break;
  default:
    // Brain.Screen.print("diff_side_final");
    diff_side_shoot_opp();
    break;
  }
}

// Driver Control

void usercontrol(void)
{
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

//   if((error_pid<10)&&(error_pid>5)){
//     speed_rpm = error_pid*kp+integral_pid*ki+derivative_pid*kd+base_rpm;
//   }
//   else{
//     speed_rpm = error_pid*kp+derivative_pid*kd+base_rpm;
//   }
//   double speed_volt = (speed_rpm/620)*12;
//   if(cata.velocity(rpm)<350){
//     cata.spin(fwd, 12, volt);
//   }
//   else{
//     cata.spin(fwd, speed_volt, volt);
//   }

//   last_error = error_pid;
//   // }

// }

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

    // wait(100, msec);
  }
}