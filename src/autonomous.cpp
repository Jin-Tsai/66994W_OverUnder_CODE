#include <all_func.h>
#include "vex.h"

void same_side_15() {
  // 前進吸桿子底下的之後後退推triball
  // task free_intake = task(task1);
  // wait(500, msec);
  intake.spin(reverse, 600, rpm);
  move_deg(300, 30, 30, 0);
  wait(600, msec);
  move_deg(1200, -100, -100, 0);
  move_deg(190, -100, 0, 315);
  move_deg(1050, -100, -30, 270);
  chassis.spin(fwd, 600, rpm);
  wait(500, msec);
  chassis.stop(brake);
  intake.stop();
  wait(10, msec);

  //轉身放intake上的球
  move_deg(300, 100, 70, 285);
  move_turn(100, 0.55);
  intake.spin(fwd, 600, rpm);
  chassis.spin(reverse, 600, rpm);
  wait(600, msec);
  chassis.stop(brake);
  intake.stop(brake);

  //轉彎吸中間的球把另一顆撞進去
  move_deg(650, -30, -100, 110);
  move_turn(60, 0.6);
  intake.spin(reverse, 600, rpm);
  move_deg(1700, 80, 80, 60);
  move_deg(350, 80, 80, 59);
  TankMove(-30, -100);
  wait(500, msec);
  TankMove(0, -100);
  wait(300, msec);
  drivertrainStop(brake);
  wait(100, msec);
  move_deg(1000, -80, -80, 2);
  TankMove(100, 100);
  wait(400, msec);
  drivertrainStop(brake);

  //轉身放 intake 上的那顆
  move_deg(250, 80, 80, 2);
  move_turn(180, 0.6);
  intake.stop();
  intake.spin(fwd, 600, rpm);
  TankMove(-100, -100);
  wait(500, msec);
  drivertrainStop(brake);
  intake.stop();

  //去吸最後一顆
  move_deg(500, -80, -80, 0);
  move_turn(306, 0.5);
  // wait(1000, msec);
  intake.spin(reverse, 600, rpm);
  move_deg(600, 80, 80, 306);
  move_deg(500, 25, 25, 306);
  wait(300, msec);

  //轉彎去放最後一顆
  move_deg(100, -80, -80, 306);
  move_turn(160, 0.6);
  move_deg(700, 80, 80, 160);
  intake.spin(fwd, 600, rpm);
  TankMove(-100, -100);
  wait(500, msec);
  drivertrainStop(brake);
  intake.stop(brake);
  move_deg(200, -100, -100, 180);

}