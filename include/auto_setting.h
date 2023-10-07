#include "vex.h"
using namespace vex;

extern double current_speed;
extern double integral, derivative;
extern double kp;
extern double ki;
extern double kd; 

void pidReset();
double g_heading(double Target);
void move_turn(double target, double kp);
void move_deg(double wanted_deg, double left_speed, double right_speed, double rotate);

double transfer_y(double input, double imin, double iMax);
void TankMove(double left_speed, double right_speed);
void drivertrainStop(brakeType _brake);