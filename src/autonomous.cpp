#include <all_func.h>
#include "vex.h"

void same_side_no_scoop() {
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

int task_open_lwing(){
  wait(350, msec);
  l_wing.set(true);
  return 0;
}

int task_close_lwing(){
  wait(300, msec);
  l_wing.set(false);
  return 0;
}


void same_side_awp_no_bar(){
  // 吸到 bar 下面的球=======
  intake.spin(reverse, 600, rpm);
  wait(100, msec);
  move_deg(200, 10, 10, 0);
  wait(500, msec); 

  //後退撈 match load + 推進
  move_no_stop(180, -30, -30, 0);
  move_no_stop(1000, -70, -70, 0);
  move_deg(130, -20, -20, 0);
  intake.stop(brake);
  wait(100, msec);
  move_deg(190, -60, 0, 310);
  task open_lwing = task(task_open_lwing);
  move_deg(950, -60, -60, 310);
  move_turn(310, 0.6);
  // wait(1000, msec); //測試用wait
  task close_lwing = task(task_close_lwing);
  move_no_stop(400, -65, -65, 307);
  move_no_stop(500, -70, -27, 280);
  // wait(1000, msec); //測試用wait
  TankMove(100, 50);
  wait(400, msec);
  drivertrainStop(brake);
  wait(10, msec);

  //轉身放intake裡的 triball
  move_deg(250, 30, 90, 300);
  wait(50, msec);
  // wait(1000, msec); //測試用wait
  move_turn(98, 0.6);
  // wait(1000, msec); //測試用wait
  wait(50, msec);
  intake.spin(fwd, 400, rpm);
  wait(100, msec);
  TankMove(-100, -60);
  wait(450, msec);
  drivertrainStop(brake);
  intake.stop(brake);
  wait(50, msec);
  // wait(1000, msec); //測試用wait

  //吸左邊的 triball
  move_deg(600, -50, -50, 95);
  // wait(1000, msec); //測試用wait
  move_turn(15, 0.5);
  // wait(1000, msec); //測試用wait
  intake.spin(reverse, 600, rpm);
  move_no_stop(200, 30, 30, 15);
  move_no_stop(2000, 80, 80, 15);
  move_deg(600, 30, 30, 15);
  wait(400, msec);

  //轉彎開 wing 推下面的
  // wait(1000, msec); //測試用wait
  // while((Inertial.heading()>0)&&(Inertial.heading()<305)){
  //   TankMove(50, -50);
  // }
  // while(Inertial.heading()>305){
  //   TankMove(20, -20);
  // }
  // drivertrainStop(brake);
  move_turn(-70, 0.55);
  intake.stop(brake);

  // wait(1000, msec); //測試用wait
  wait(50, msec);
  move_deg(800, -50, -50, 280);

  r_wing.set(true);

  // wait(1000, msec); //測試用wait
  wait(50, msec);

  // while((Inertial.heading()<358)&&(Inertial.heading()>1)){
  //   TankMove(-20, 20);
  // }
  // drivertrainStop(brake);

  // TankMove(-20, 20);
  // wait(100, msec);
  move_turn(358, 0.5);

  wait(100, msec);
  // wait(1000, msec); //測試用wait

  move_no_stop(200, -30, -30, 358);//開wing往後推
  move_no_stop(700, -80, -80, 358);
  move_deg(200, -30, -30, 358);
  TankMove(50, 50);
  wait(300, msec);
  drivertrainStop(brake);
  wait(50, msec);
  // wait(1000, msec); //測試用wait

  r_wing.set(false);
  move_deg(200, 30, 30, 358);
  move_turn(178, 0.55);//轉 180 放球
  // wait(1000, msec); //測試用wait
  intake.spin(fwd, 400, rpm);
  wait(50, msec);
  TankMove(-30, -30);
  wait(500, msec);
  drivertrainStop(brake);
  intake.stop(brake);

  

}

void same_side_awp(){
  // 吸到 bar 下面的球=======
  intake.spin(reverse, 600, rpm);
  wait(100, msec);
  move_deg(200, 10, 10, 0);
  wait(500, msec); 

  //後退撈 match load + 推進

  move_no_stop(180, -30, -30, 0);
  move_no_stop(1000, -70, -70, 0);
  move_new_deg(-1000, 70, 40, -50, 0.5);
  intake.stop(brake);
  // wait(1000, msec); //測試用wait

  l_wing.set(true);
  move_new_deg(-650, 70, 40, 285, 0.7);
  wait(100, msec);
  l_wing.set(false);
  move_new_deg(-600, 70, 90, 270, 1.0);
  // wait(1000, msec); //測試用wait
  TankMove(100, 100);
  wait(300, msec);
  drivertrainStop(brake);
  // wait(100000000, msec);

  //轉身放intake裡的 triball
  move_deg(250, 30, 90, 300);
  wait(50, msec);
  // wait(1000, msec); //測試用wait
  move_turn(100, 0.6);
  // wait(1000, msec); //測試用wait
  wait(50, msec);
  intake.spin(fwd, 400, rpm);
  wait(100, msec);
  TankMove(-100, -60);
  wait(450, msec);
  drivertrainStop(brake);
  intake.stop(brake);
  wait(50, msec);
  // wait(1000, msec); //測試用wait

  //吸左邊的 triball
  move_deg(600, -50, -50, 95);
  // wait(1000, msec); //測試用wait
  move_turn(15, 0.5);
  // wait(1000, msec); //測試用wait
  intake.spin(reverse, 600, rpm);
  move_no_stop(200, 30, 30, 15);
  move_no_stop(2000, 80, 80, 15);
  move_deg(600, 30, 30, 15);
  wait(400, msec);

  //放左邊的球
  move_turn(140, 0.6);
  intake.stop(brake);
  // move_no_stop(200, 30, 30, 140);
  // move_no_stop(900, 80, 80, 140);
  // move_deg(200, 30, 30, 140);
  move_new_deg(1300, 70, 30, 180, 0.25);
  // wait(1000, msec); //測試用wait

  // move_turn(180, 0.5);
  intake.spin(fwd, 400, rpm);
  wait(50, msec);
  TankMove(-50, -50);
  wait(550, msec);
  drivertrainStop(brake);
  intake.stop(brake);
  wait(100, msec);
  // wait(1000, msec); //測試用wait

  //去碰 elevation bar

  move_new_deg(-2500, 70, 30, 90, 0.35);
  // wait(1000, msec); //測試用wait
  TankMove(30, 30);
  wait(500, msec);
  drivertrainStop(brake);
  wait(100, msec);
  move_new_deg(50, 70, 30, 90, 0.35);
  // wait(1000, msec); //測試用wait
  move_turn(78, 0.6);
  l_wing.set(true);

}

void diff_side_awp_no_middle(){
  
}

void diff_side_awp_middle(){
  intake.spin(reverse, 600, rpm);
  move_new_deg(2800, 70, 40, 15, 0.5);
  move_new_deg(250, 20, 40, 15, 0.4);
  wait(600, msec);

  move_new_deg(-2600, 70, 40, 45, 0.4);
  wait(100, msec);
  move_turn(-25, 0.5);
  intake.stop(brake);
  // wait(1000, msec); //測試用wait
  l_wing.set(true);
  move_new_deg(-500, 70, 70, 280, 1.2);
  // wait(1000, msec); //測試用wait
  wait(100, msec);
  l_wing.set(false);

  move_new_deg(-800, 70, 70, 270, 1.2);
  // wait(1000, msec); //測試用wait
  move_new_deg(-750, 70, 40, 265, 0.4);
  // wait(1000, msec); //測試用wait
  r_wing.set(true);
  wait(1000, msec); //測試用wait

}

void auto_skills(){

  move_new_deg(-1700, 70, 40, 90, 0.9);

  TankMove(100, 100);
  wait(500, msec);
  drivertrainStop(brake);
  wait(10, msec);

  move_deg(200, 60, 60, 90);
  // wait(1000, msec); //測試用wait
  move_turn(55, 0.5);
  // wait(1000, msec); //測試用wait
  move_deg(400, 60, 60, 55);
  // wait(1000, msec); //測試用wait
  move_turn(163, 0.53);
  // wait(1000, msec); //測試用wait
  
  TankMove(-20, -20);
  wait(300, msec);
  drivertrainStop(brake);
  TankMove(-10, 0);
  wait(300, msec);
  drivertrainStop(brake);
  wait(10, msec);

  wait(1000, msec); //測試用wait

  // while(Brain.Timer.time(seconds)<30){
  //   if((rotation_sensor.angle()>310)){
  //     cata.spin(reverse, 200, rpm);
  //   }
  //   else if((rotation_sensor.angle()<310)){
  //     cata.stop(brake);
  //     cata.spin(fwd, 200, rpm);
  //     wait(150, msec);
  //     cata.stop(brake);
  //     wait(5, msec);
  //   }
  // }
  // cata.stop(brake);

  move_turn(222, 0.5);
  // wait(1000, msec); //測試用wait
  move_new_deg(-670, 70, 40, 222, 0.45);
  // wait(1000, msec); //測試用wait
  TankMove(0, -30);
  wait(500, msec);
  drivertrainStop(brake);
  wait(1000, msec); //測試用wait

  // while(Brain.Timer.time(seconds)<7){
  //   if((rotation_sensor.angle()>310)){
  //     cata.spin(reverse, 200, rpm);
  //   }
  //   else if((rotation_sensor.angle()<310)){
  //     cata.stop(brake);
  //     cata.spin(fwd, 200, rpm);
  //     wait(150, msec);
  //     cata.stop(brake);
  //     wait(5, msec);
  //   }
  // }
  // cata.stop(brake);

  move_new_deg(-4300, 70, 40, 180, 0.53); //轉彎到 1200
  // wait(1000, msec); //測試用wait
  move_new_deg(-2000, 70, 40, 89, 0.37);
  // wait(1000, msec); //測試用wait

  TankMove(100, 100);
  wait(1000, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait
  move_new_deg(200, 100, 40, 90, 0.5);
  TankMove(100, 100);
  wait(500, msec);
  drivertrainStop(brake);
  wait(1000, msec); //測試用wait

  move_new_deg(200, 70, 40, 90, 0.5);
  // wait(1000, msec); //測試用wait
  move_turn(180, 0.5);
  // wait(1000, msec); //測試用wait
  TankMove(30, 30);
  wait(500, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait

  move_new_deg(1200, 70, 40, 180, 0.5);
  // wait(1000, msec); //測試用wait
  move_turn(25, 0.6);
  // wait(1000, msec); //測試用wait

  // move_new_deg(-1500, 70, 40, 20, 0.5);
  // wait(1000, msec); //測試用wait
  // r_wing.set(true);
  // l_wing.set(true);

  move_new_deg(-2600, 70, 40, 100, 0.4);
  // wait(1000, msec); //測試用wait
  r_wing.set(true);
  l_wing.set(true);
  move_turn(180, 0.5);
  // wait(1000, msec); //測試用wait
  
  move_new_deg(-1000, 70, 40, 180, 0.3);
  TankMove(70, 70);
  wait(400, msec);
  drivertrainStop(brake);
  wait(1000, msec); //測試用wait
  move_new_deg(200, 70, 40, 180, 0.3);

}

void test(){
}