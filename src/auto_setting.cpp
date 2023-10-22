#include "vex.h"
#include <all_func.h>

double current_speed;
double integral, derivative;
double kp = 0.0011;
double ki = 0.0000025;
double kd = 0.00002; 

double transfer_y(double input, double imin, double iMax) {
  return (iMax - input) * 240 / (iMax - imin);
}

void TankMove(double left_speed, double right_speed) {
  left_front.spin(fwd, left_speed, pct);
  left_back.spin(fwd, left_speed, pct);

  right_front.spin(fwd, right_speed, pct);
  right_back.spin(fwd, right_speed, pct);
 
}

void drivertrainStop(brakeType _brake) {
  left_front.stop(_brake);
  left_back.stop(_brake);

  right_front.stop(_brake);
  right_back.stop(_brake);
}

void pidReset() {
  integral = 0;
  derivative = 0;
}

double g_heading(double Target) {
  double value = Inertial.heading() - Target;
  if(value<180) return -value;
  return 360-value;
}

void move_turn(double target, double t_kp) {
  double error = g_heading(target);
  double turn_speed = 0;
  while (abs(error) > 1) {
    error = g_heading(target);
    turn_speed = error * t_kp;
    TankMove(-turn_speed, turn_speed);
  }
  drivertrainStop(brake);
  wait(10, msec);
}

void move_deg(double wanted_deg, double left_speed, double right_speed, double rotate) {
  left_front.resetPosition();
  left_back.resetPosition();
  right_front.resetPosition();
  right_back.resetPosition();
  
  double error = g_heading(rotate);
  double turn_speed = 0;
  double sum_deg = 0;
  while (abs(sum_deg) < abs(wanted_deg)) {
    sum_deg = ((fabs(left_back.position(deg)) + fabs(left_front.position(deg)) +
               fabs(right_back.position(deg)) + fabs(right_front.position(deg)))
             / 4);
    error = g_heading(rotate);
    turn_speed = error * kp;
    TankMove(-(left_speed + turn_speed), -(right_speed - turn_speed));
  }
  drivertrainStop(brake);
  wait(10, msec);
}

void move_new_deg(double wanted_deg, double max_speed,double max_turn_speed, double rotate, double kp) {
  left_front.resetPosition();
  left_back.resetPosition();
  right_front.resetPosition();
  right_back.resetPosition();
  
  double error = g_heading(rotate);
  double turn_speed = 0;
  double sum_deg = 0;
  double straight_kp=0.3;
  double straight_speed=0;
  double straight_direction = wanted_deg/fabs(wanted_deg);
  wanted_deg = fabs(wanted_deg);
  while (sum_deg < wanted_deg) {
    sum_deg = ((fabs(left_back.position(deg)) + fabs(left_front.position(deg)) +
               fabs(right_back.position(deg)) + fabs(right_front.position(deg)))
             / 4);
    straight_speed = (wanted_deg-straight_speed)*straight_kp;
    if(fabs(straight_speed) > max_speed) straight_speed = max_speed;
    straight_speed*= straight_direction;
    error = g_heading(rotate);
    turn_speed = error * kp;
    if(fabs(turn_speed)>fabs(max_turn_speed)){
      turn_speed = max_turn_speed *turn_speed/fabs(turn_speed);
    } 
    TankMove(-(straight_speed + turn_speed), -(straight_speed - turn_speed));
  }
  drivertrainStop(brake);
  wait(10, msec);
}

void move_no_stop(double wanted_deg, double left_speed, double right_speed, double rotate){
  left_front.resetPosition();
  left_back.resetPosition();
  right_front.resetPosition();
  right_back.resetPosition();
  
  double error = g_heading(rotate);
  double turn_speed = 0;
  double sum_deg = 0;
  while (abs(sum_deg) < abs(wanted_deg)) {
    sum_deg = ((fabs(left_back.position(deg)) + fabs(left_front.position(deg)) +
               fabs(right_back.position(deg)) + fabs(right_front.position(deg)))
             / 4);
    error = g_heading(rotate);
    turn_speed = error * kp;
    TankMove(-(left_speed + turn_speed), -(right_speed - turn_speed));
  }
}