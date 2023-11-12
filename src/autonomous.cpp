#include <all_func.h>
#include "vex.h"

int task_cata_pos(){
  // if((rotation_sensor.angle()>330)){
      cata.spin(reverse, 200, rpm);
      waitUntil(rotation_sensor.angle()<305);
      cata.stop(hold);
  // }
  return 0;
}

void same_side_no_scoop() {
  // 前進吸桿子底下的之後後退推triball
  // task free_intake = task(task1);
  // wait(500, msec);
  intake.spin(reverse, 600, rpm);
  move_deg(320, 30, 30, 0);
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

  task cata_lower = task(task_cata_pos);
  wait(200, msec);

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
  wait(200, msec); //測試用wait
  move_new_deg(-600, 70, 90, 270, 1.1);
  TankMove(100, 100);
  wait(350, msec);
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
  move_turn(17, 0.5);
  // wait(1000, msec); //測試用wait
  intake.spin(reverse, 600, rpm);
  move_no_stop(200, 30, 30, 17);
  move_no_stop(2000, 80, 80, 17);
  move_deg(600, 30, 30, 17);
  wait(500, msec);

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
  wait(200, msec);
  TankMove(-50, -50);
  wait(550, msec);
  drivertrainStop(brake);
  intake.stop(brake);
  wait(100, msec);
  // wait(1000, msec); //測試用wait

  //去碰 elevation bar

  // TankMove(100, 100);
  // wait(600, msec);
  // drivertrainStop(brake);

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

int task_lower_cata(){
  cata.spin(reverse, 200, rpm);
  wait(100, msec);
  while(rotation_sensor.angle()>310){
    cata.spin(reverse, 200, rpm);
  }
  Controller1.rumble(".-.");
  cata.stop(hold);
  return 0;
}
int task_starting(){
  cata.spin(reverse, 200, rpm);
  while(rotation_sensor.angle()>290){
    cata.spin(reverse, 200, rpm);
  }
  cata.stop(hold);
  return 0;
}

void diff_side_awp_middle(){

  task start_cata = task(task_starting);
  // Inertial.setHeading(45,deg);
  intake.spin(reverse, 600, rpm);
  move_new_deg(2240, 80, 40, 17, 0.65);
  move_new_deg(300, 23, 40, 17, 0.35);
  wait(700, msec);
  
  move_new_deg(-1000, 40, 40, 5, 0.4);
  // wait(1000, msec); //測試用wait
  move_turn(-115, 0.6);
  // intake.stop(brake);
  wait(500, msec);
  // intake.stop(brake);

  cata.spin(reverse, 200, rpm);
  wait(100, msec);
  cata.stop(coast);
  intake.stop(brake);
  // task lower_cata = task(task_lower_cata);

  move_turn(35, 0.57);
  move_new_deg(-1530, 70, 40, 45, 0.9);
  wait(50, msec);
  move_turn(-23, 0.5);
  // wait(1000, msec); //測試用wait
  l_wing.set(true);
  move_new_deg(-300, 70, 70, 285, 1.2);
  // wait(1000, msec); //測試用wait
  wait(100, msec);
  l_wing.set(false);
  // wait(1000, msec); //測試用wait

  move_new_deg(-800, 50, 50, 270, 0.6);
  wait(100, msec);
  move_new_deg(-1250, 35, 40, 270, 0.3);
  // wait(1000, msec); //測試用wait
  r_wing.set(true);
  // wait(1000, msec); //測試用wait

  TankMove(10, 10);
  wait(400, msec);
  drivertrainStop(brake);
  TankMove(-10, 0);
  wait(550, msec);
  drivertrainStop(brake);
  wait(1000, msec); //測試用wait

}

// int task_lower_cata(){
//   cata.spin(reverse, 200, rpm);
//   wait(100, msec);
//   while(rotation_sensor.angle()>310){
//     cata.spin(reverse, 200, rpm);
//   }
//   // Controller1.rumble(".-.");
//   cata.stop(hold);
//   return 0;
// }

void auto_skills(){
  task start_cata = task(task_lower_cata);

  Inertial.setHeading(40,deg);
  // move_turn(40, 0.6);
  move_new_deg(500, 70, 40, 40, 0.4);
  move_turn(-19, 0.6);
  TankMove(-17, -17);
  wait(200, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait


  // wait(100000000, msec); //測試用wait

  while(Brain.Timer.time(seconds)<44){ //43
    cata.spin(reverse, 12, volt);
  }
  cata.stop(hold);

  if(rotation_sensor.angle()>340){
    while(rotation_sensor.angle()>305){
      cata.spin(reverse, 12.0, volt);
    }
    cata.stop(hold);
  }

  move_turn(40, 0.5); 
  // wait(1000, msec); //測試用wait
  move_new_deg(-750, 70, 40, 40, 0.45);
  // wait(1000, msec); //測試用wait
  // TankMove(0, -30);
  // wait(450, msec);
  // drivertrainStop(brake);
  move_turn(2, 0.5);
  // wait(1000, msec); //測試用wait

  // waitUntil(Brain.Timer.time(seconds)>40);
  // wait(1000000000, msec); //測試用wait

  move_new_deg(-4400, 90, 40, -1, 0.6); //轉彎到 1200
  // wait(1000000000, msec); //測試用wait
  cata.stop(coast);

  move_new_deg(-1800, 80, 80, -90, 0.54);
  // wait(1000, msec); //測試用wait

  TankMove(100, 100);
  wait(700, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait
  move_new_deg(300, 100, 40, 280, 0.5);
  TankMove(100, 100);
  wait(700, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait

  // move_new_deg(1100, 70, 40, 0, 0.5);
  // wait(1000, msec); //測試用wait
  move_new_deg(200, 60, 40, 280, 0.5);
  // wait(1000, msec); //測試用wait
  move_turn(197, 0.6);
  // wait(1000, msec); //測試用wait
  // r_wing.set(true);
  
  move_new_deg(-800, 80, 40, 197, 0.4);
  l_wing.set(true);
  move_new_deg(-600, 80, 40, 197, 0.4);
  // wait(1000, msec); //測試用wait
  // l_wing.set(false);
  move_new_deg(-1370, 50, 40, 290, 0.15);
  l_wing.set(false);
  r_wing.set(true);
  // wait(1000, msec); //測試用wait
  while(Inertial.heading()<330){
    TankMove(0, 40);
  }
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait
  move_turn(-10, 0.6);
  l_wing.set(true);
  r_wing.set(true);

  move_new_deg(-300, 100, 40, 0, 0.4);
  TankMove(100, 100);
  wait(550, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait

  l_wing.set(false);
  r_wing.set(false);

  move_new_deg(200, 70, 50, 0, 0.3);
  move_turn(180, 0.6);
  r_wing.set(true);

  move_new_deg(-1300, 70, 50, 270, 0.6);
  // wait(1000, msec); //測試用wait
  
  // wait(1000, msec); //測試用wait
  while(Inertial.heading()<330){
    TankMove(0, 40);
  }
  drivertrainStop(brake);
  move_turn(20, 0.6);
  l_wing.set(true);
  r_wing.set(true);

  move_new_deg(-800, 100, 40, 0, 0.3);
  TankMove(100, 100);
  wait(500, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait
  move_new_deg(400, 100, 40, 0, 0.3);



}

void test(){
}