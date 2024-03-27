#include <all_func.h>
#include "vex.h"

int task_cata_pos(){
  // if((rotation_sensor.angle()>330)){
      // r_back.set(true);
      cata.spin(reverse, 200, rpm);
      waitUntil(rotation_sensor.angle()>40);
      cata.stop(hold);
      // r_back.set(false);
  // }
  return 0;
}

void far_6_elevation() {

  // 前進吸桿子底下的之後後退推triball
  intake.spin(fwd, 12, volt);
  move_new_deg(100, 40, 30, 0, 0.34);
  // wait(1000, msec); //測試用wait
  wait(150, msec);

  r_back.set(true);
  move_no_stop(150, -50, -50, 0);
  move_no_stop(470, -70, -70, 0);
  // wait(300, msec);
  // move_no_stop(750, -70, -70, 0);
  move_new_deg(-910, 80, 40, -45, 0.45);
  
  wait(50, msec);
  // wait(1000, msec); //測試用wait

  l_back.set(true);
  wait(50, msec);
  move_new_deg(-700, 70, 50, 270, 0.55);
  // wait(1000, msec); //測試用wait
  l_back.set(false);
  wait(200, msec);
  // wait(1000, msec); //測試用wait
  move_new_deg(-450, 70, 80, 260, 0.8);
  intake.stop(brake);
  TankMove(70, 70);
  wait(400, msec);
  drivertrainStop(brake);

  move_new_deg(400, 70, 80, 260, 0.8);
  r_back.set(false);
  move_turn(105, 0.45);
  intake.spin(reverse, 12, volt);
  TankMove(-80, -80);
  wait(500, msec);
  drivertrainStop(brake);
  wait(100, msec);

  // wait(1000, msec); //測試用wait

  //轉彎吸中左
  move_new_deg(-450, 40, 40, 90, 0.4);
  wait(150, msec);
  move_turn(17, 0.4);
  intake.spin(fwd, 12, volt);
  wait(100, msec);
  // wait(1000, msec); //測試用wait
  move_no_stop(200, 30, 30, 17);
  move_no_stop(1800, 90, 90, 17);
  move_new_deg(300, 50, 50, 17, 0.4);
  wait(50,msec);
  move_new_deg(-150, 70, 40, 17, 0.4);
  move_turn(140, 0.45);
  intake.stop(brake);
  intake.spin(reverse, 12, volt);
  // wait(1000, msec); //測試用wait
  move_new_deg(550, 70, 40, 180, 0.5);
  // wait(1000, msec); //測試用wait
  TankMove(-90, -70);
  wait(500, msec);
  drivertrainStop(brake);
  wait(100, msec);
  // wait(1000, msec); //測試用wait

  move_new_deg(-400, 75, 40, 180, 0.4);
  wait(100, msec);
  move_turn(0, 0.45);
  intake.spin(fwd, 12, volt);
  move_new_deg(500, 50, 40, 0, 0.4);
  move_turn(35, 0.45);
  move_new_deg(580, 70, 40, 35, 0.4);
  move_turn(0, 0.5);

  r_back.set(true);
  move_no_stop(600, -80, -80, 0);
  TankMove(80, 80);
  wait(200, msec);
  drivertrainStop(brake);

  move_new_deg(200, 70, 80, 0, 0.8);
  r_back.set(false);
  move_turn(180, 0.45);
  intake.spin(reverse, 12, volt);
  TankMove(-80, -80);
  wait(350, msec);
  drivertrainStop(brake);
  move_new_deg(-250, 70, 40, 180, 0.4);

  wait(100000, sec);
}

void far_6_elevation_safe3() {

  // 前進吸桿子底下的之後後退推triball
  intake.spin(fwd, 12, volt);
  move_new_deg(100, 40, 30, 0, 0.34);
  // wait(1000, msec); //測試用wait
  wait(150, msec);

  r_back.set(true);
  move_no_stop(150, -50, -50, 0);
  move_no_stop(450, -70, -70, 0);
  // wait(300, msec);
  // move_no_stop(750, -70, -70, 0);
  move_new_deg(-920, 80, 40, -45, 0.45);
  
  wait(50, msec);
  // wait(1000, msec); //測試用wait

  l_back.set(true);
  wait(50, msec);
  move_new_deg(-600, 70, 50, 270, 0.55);
  // wait(1000, msec); //測試用wait
  l_back.set(false);
  wait(200, msec);
  // wait(1000, msec); //測試用wait
  move_new_deg(-550, 70, 80, 260, 0.8);
  intake.stop(brake);
  TankMove(70, 70);
  wait(400, msec);
  drivertrainStop(brake);

  move_new_deg(400, 70, 80, 260, 0.8);
  r_back.set(false);
  move_turn(105, 0.45);
  intake.spin(reverse, 12, volt);
  TankMove(-80, -80);
  wait(500, msec);
  drivertrainStop(brake);
  wait(100, msec);

  // wait(1000, msec); //測試用wait

  //轉彎吸中左
  move_new_deg(-450, 50, 40, 90, 0.4);
  wait(50, msec);
  move_turn(18, 0.4);
  intake.spin(fwd, 12, volt);
  wait(100, msec);
  // wait(1000, msec); //測試用wait
  move_no_stop(200, 30, 30, 18);
  move_no_stop(1750, 80, 80, 18);
  move_new_deg(300, 50, 50, 18, 0.4);
  wait(50,msec);
  move_new_deg(-150, 70, 40, 18, 0.4);
  move_turn(150, 0.45);
  intake.stop(brake);
  intake.spin(reverse, 12, volt);
  move_new_deg(400, 70, 40, 150, 0.4);
  wait(100, msec);
  move_turn(90, 0.41);
  intake.stop(brake);
  intake.spin(fwd, 12, volt);
  move_new_deg(450, 70, 40, 90, 0.4);
  move_turn(180, 0.45);
  intake.stop(brake);
  intake.spin(reverse, 12, volt);
  r_front.set(true);
  l_front.set(true);
  move_no_stop(200, 60, 60, 180);
  TankMove(-80, -80);
  wait(300, msec);
  drivertrainStop(brake);
  wait(100, msec);

  r_front.set(false);
  l_front.set(false);
  move_new_deg(-300, 70, 40, 180, 0.4);
  move_turn(17, 0.45);
  intake.spin(fwd, 12, volt);
  move_new_deg(800, 70, 40, 17, 0.4);

  move_new_deg(-150, 70, 40, 17, 0.4);
  move_turn(180, 0.45);
  move_no_stop(200, 60, 60, 180);
  TankMove(-100, -100);
  wait(350, msec);
  drivertrainStop(brake);
  move_new_deg(-250, 70, 40, 180, 0.4);

}

int task_open_lwing(){
  wait(350, msec);
  l_back.set(true);
  return 0;
}

int task_close_lwing(){
  wait(300, msec);
  l_back.set(false);
  return 0;
}

void far_awp_no_bar(){
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

  r_back.set(true);

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

  r_back.set(false);
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

void far_4_bar(){

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

  l_back.set(true);
  move_new_deg(-650, 70, 40, 285, 0.7);
  wait(100, msec);
  l_back.set(false);
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
  l_back.set(true);

}

int wing_hit_start(){
  wait(50, msec);
  r_front.set(true);
  wait(400, msec);
  r_front.set(false);

  return 0;
}

int outtake_ball(){
  wait(300, msec);
  intake.spin(reverse, 12, volt);

  return 0;
}

void far_6_middle(){
  Inertial.setHeading(70,deg);
  task hit_wing = task(wing_hit_start);
  intake.spin(fwd, 12, volt);

  move_no_stop(200, 50, 50, 70);
  move_no_stop(1500, 90, 90, 70);
  move_no_stop(290, 60, 60, 70);
  move_new_deg(240, 30, 30, 70, 0.3);
  wait(50, msec);
  move_no_stop(200, -50, -50, 90);
  move_no_stop(1670, -100, -100, 90);
  move_new_deg(-300, 50, 40, 90, 0.6);
  wait(100, msec);

  move_turn(90, 0.46);
  TankMove(30, 30);
  wait(550, msec);
  drivertrainStop(brake);
  intake.stop(brake);

  move_new_deg(300, 70, 30, 90, 0.3);
  task spitout = task(outtake_ball);
  move_turn(130, 0.44);
  wait(100, msec);
  move_turn(0, 0.44);
  intake.stop(brake);
  intake.spin(fwd, 12, volt);
  move_new_deg(1320, 80, 30, 0, 0.4);
  wait(150, msec);

  r_back.set(true);
  move_no_stop(150, -50, -50, 0);
  move_no_stop(470, -70, -70, 0);
  // wait(300, msec);
  // move_no_stop(750, -70, -70, 0);
  move_new_deg(-920, 80, 40, -45, 0.45);
  
  wait(50, msec);
  // wait(1000, msec); //測試用wait

  l_back.set(true);
  wait(50, msec);
  move_new_deg(-700, 70, 50, 270, 0.55);
  // wait(1000, msec); //測試用wait
  l_back.set(false);
  wait(200, msec);
  // wait(1000, msec); //測試用wait
  move_new_deg(-450, 70, 80, 260, 0.8);
  intake.stop(brake);
  TankMove(70, 70);
  wait(400, msec);
  drivertrainStop(brake);

  move_new_deg(300, 70, 80, 260, 0.8);
  r_back.set(false);
  move_turn(107, 0.45);
  intake.spin(reverse, 12, volt);
  TankMove(-80, -80);
  wait(500, msec);
  drivertrainStop(brake);
  wait(100, msec);

  move_new_deg(-480, 40, 40, 90, 0.4);
  wait(150, msec);
  move_turn(17, 0.4);
  intake.spin(fwd, 12, volt);
  wait(100, msec);
  // wait(1000, msec); //測試用wait
  move_no_stop(200, 30, 30, 17);
  move_no_stop(1800, 90, 90, 17);
  move_new_deg(300, 50, 50, 17, 0.4);
  wait(50,msec);
  move_new_deg(-150, 70, 40, 17, 0.4);
  move_turn(140, 0.45);
  intake.stop(brake);
  intake.spin(reverse, 12, volt);
  // wait(1000, msec); //測試用wait
  move_new_deg(550, 70, 40, 180, 0.5);
  // wait(1000, msec); //測試用wait
  TankMove(-90, -70);
  wait(500, msec);
  drivertrainStop(brake);
  wait(100, msec);
  move_new_deg(-350, 70, 40, 180, 0.5);

  wait(1000000,sec);

}

void far_6_middle_flywheel(){
  
  Inertial.setHeading(0,deg);
  intake.spin(fwd, 600, rpm);
  cata.spin(fwd, 60, rpm);
  move_new_deg(2950, 80, 65, -54, 0.5);
  TankMove(0, -30);
  wait(550, msec);
  drivertrainStop(brake);
  wait(100, msec);
  r_back.set(true);
  l_back.set(true);
  move_new_deg(-1500, 80, 50, 270, 0.4);
  l_back.set(false);
  r_back.set(false);
  TankMove(70, 70);
  wait(300, msec);
  drivertrainStop(brake);

  move_new_deg(200, 70, 40, 270, 0.35);
  move_turn(237, 0.56);
  move_new_deg(1500, 70, 40, 237, 0.35);
  cata.stop(brake);

  TankMove(-50, 0);
  wait(340, msec);
  drivertrainStop(brake);
  wait(100, msec);
  TankMove(-45, -45);
  wait(300, msec); 
  drivertrainStop(brake);

  move_new_deg(-300, 80, 50, 270, 0.4);
  // wait(1000, msec); //測試用wait
  move_turn(129, 0.55);
  intake.stop(brake);
  intake.spin(reverse, 400, rpm);
  move_new_deg(1000, 80, 50, 129, 0.4);
  wait(100, msec);
  // move_new_deg(-200, 60, 50, 125, 0.4);

  move_turn(180, 0.52);
  // wait(1000, msec); //測試用wait
  move_new_deg(1300, 60, 80, 180, 0.4);//280 uturn
  // wait(1000, msec); //測試用wait
  cata.spin(fwd, 50, rpm);
  move_turn(269, 0.5);
  
  // move_new_deg(1500, 50, 70, 270, 0.45);
  intake.stop(brake);
  intake.spin(fwd, 600, rpm);
  move_new_deg(1300, 70, 40, 269, 0.4);
  // move_new_deg(700, 40, 30, 270, 0.34);
  // wait(10000000, msec); //測試用wait
  // TankMove(-10, -10);
  // wait(600, msec);
  // drivertrainStop(brake);
  wait(300, msec);

  move_no_stop(180, -30, -30, 270);
  move_no_stop(950, -70, -70, 270);
  move_new_deg(-1000, 60, 40, 220, 0.45);
  
  wait(50, msec);

  l_back.set(true);
  wait(100, msec);
  move_new_deg(-300, 70, 50, 190, 0.7);
  // wait(1000, msec); //測試用wait
  l_back.set(false);
  wait(100, msec);
  r_back.set(true);
  wait(100, msec); //測試用wait
  move_new_deg(-550, 70, 80, 180, 0.8);
  cata.stop(brake);
  TankMove(40, 40);
  wait(600, msec);
  drivertrainStop(brake);

  // move_new_deg(300, 80, 30, 180, 0.4);
  // wait(100, msec);
  // TankMove(80, 82);
  // wait(450, msec);
  // drivertrainStop(brake);

  move_new_deg(420, 70, 50, 180, 0.4);
  TankMove(80, 60);
  wait(500, msec);
  drivertrainStop(brake);
  move_deg(100, 90, 30, 210);
  wait(50, msec);
  intake.stop(brake);
  // r_back.set(false);

}

// uturn need to change
void far_5_middle(){
  Inertial.setHeading(0,deg);
  intake.spin(fwd, 600, rpm);
  cata.spin(reverse, 50, rpm);
  move_new_deg(2500, 80, 65, -19, 0.75);
  // TankMove(-20, -20);
  // wait(500, msec);
  // drivertrainStop(brake);
  wait(200, msec);

  move_new_deg(-200, 70, 40, -17, 0.35);
  // wait(1000, msec); //測試用wait
  intake.stop(brake);
  move_turn(88, 0.54);
  intake.spin(reverse, 600, rpm);
  wait(100, msec);
  TankMove(-80, -80);
  wait(500, msec);
  // TankMove(-40, -40);
  // wait(100, msec);
  drivertrainStop(brake);
  // wait(100, msec);

  move_new_deg(-300, 70, 40, 90, 0.35);
  move_turn(237, 0.56);
  intake.spin(fwd, 600, rpm);
  move_new_deg(1100, 70, 40, 237, 0.35);
  TankMove(-50, 0);
  wait(340, msec);
  drivertrainStop(brake);
  wait(300, msec);
  TankMove(-40, -40);
  wait(300, msec); 
  drivertrainStop(brake);

  move_new_deg(-200, 80, 50, 270, 0.4);
  // wait(1000, msec); //測試用wait
  move_turn(129, 0.55);
  intake.stop(brake);
  intake.spin(reverse, 450, rpm);
  move_new_deg(1000, 80, 50, 129, 0.4);
  wait(200, msec);
  // move_new_deg(-200, 60, 50, 125, 0.4);

  move_turn(180, 0.52);
  // wait(1000, msec); //測試用wait
  move_new_deg(1500, 60, 80, 180, 0.4);//280 uturn
  // wait(1000, msec); //測試用wait
  cata.spin(fwd, 60, rpm);
  move_turn(269, 0.5);
  
  // move_new_deg(1500, 50, 70, 270, 0.45);
  intake.stop(brake);
  intake.spin(fwd, 600, rpm);
  move_new_deg(1300, 70, 40, 269, 0.4);
  // move_new_deg(700, 40, 30, 270, 0.34);
  // wait(10000000, msec); //測試用wait
  // TankMove(-10, -10);
  // wait(600, msec);
  // drivertrainStop(brake);
  wait(300, msec);

  move_no_stop(180, -30, -30, 270);
  move_no_stop(1000, -70, -70, 270);
  move_new_deg(-1000, 60, 40, 220, 0.45);
  
  wait(200, msec);

  l_back.set(true);
  wait(150, msec);
  move_new_deg(-300, 70, 50, 198, 0.7);
  wait(100, msec); //測試用wait
  l_back.set(false);
  wait(100, msec);
  r_back.set(true);
  wait(100, msec); //測試用wait
  move_new_deg(-550, 70, 80, 180, 0.8);
  cata.stop(brake);
  TankMove(40, 40);
  wait(600, msec);
  drivertrainStop(brake);

  // move_new_deg(300, 80, 30, 180, 0.4);
  // wait(100, msec);
  // TankMove(80, 82);
  // wait(450, msec);
  // drivertrainStop(brake);

  move_new_deg(420, 70, 50, 180, 0.4);
  TankMove(80, 60);
  wait(500, msec);
  drivertrainStop(brake);
  move_deg(100, 90, 30, 210);
  wait(50, msec);
  intake.stop(brake);

}

int task_lower_cata(){
  cata.spin(reverse, 200, rpm);
  wait(100, msec);
  while(rotation_sensor.angle()<40){
    cata.spin(reverse, 200, rpm);
  }
  Controller1.rumble(".-.");
  cata.stop(coast);
  return 0;
}
int task_starting(){
  cata.spin(reverse, 200, rpm);
  while(rotation_sensor.angle()<60){
    cata.spin(reverse, 200, rpm);
  }
  cata.stop(coast);
  return 0;
}

void near_awp_shoot(){

  // task start_cata = task(task_starting);
  Inertial.setHeading(20,deg);
  intake.spin(fwd, 600, rpm);
  
  move_new_deg(2050, 100, 30, 20, 0.3);
  wait(100, msec);
  move_new_deg(-1000, 90, 30, 20, 0.3);
  wait(100, msec);
  // wait(1000, msec); //測試用wait
  move_turn(50, 0.45);
  intake.stop(brake);
  // wait(1000, msec); //測試用wait
  move_new_deg(-950, 60, 30, 50, 0.3);
  wait(100, msec);
  // wait(1000, msec); //測試用wait

  // wait(100000000, msec);

  move_turn(-30, 0.35);
  cata.spin(fwd, 7, volt);
  // wait(1000, msec); //測試用wait
  wait(100, msec);
  l_back.set(true);
  wait(100, msec);
  move_new_deg(-350, 50, 30, 280, 0.6);
  // wait(1000, msec); //測試用wait
  intake.spin(fwd, 600, rpm);
  wait(100, msec);
  l_back.set(false);
  wait(100, msec);
  // wait(1000, msec); //測試用wait
  r_back.set(true);

  move_new_deg(-800, 25, 80, 270, 0.4);
  // wait(1000, msec); //測試用wait
  wait(100, msec);
  move_new_deg(-1000, 50, 30, 270, 0.3);
  // wait(1000, msec); //測試用wait

  TankMove(10, 10);
  wait(300, msec);
  drivertrainStop(brake);
  cata.stop(brake);
  intake.stop(brake);

}

void near_final_stealmid(){

  // task start_cata = task(task_starting);
  // Inertial.setHeading(45,deg);
  intake.spin(fwd, 600, rpm);
  
  move_new_deg(2200, 80, 50, 20, 0.6);
  wait(100, msec);
  cata.spin(reverse, 50, rpm);
  move_new_deg(150, 20, 20, 20, 0.35);
  wait(280, msec);
  
  move_new_deg(-200, 60, 40, 0, 0.4);
  intake.stop(brake);
  cata.stop(brake);
  cata.spin(fwd, 160, rpm);
  wait(500, msec);
  move_turn(-90, 0.6);
  // wait(1000000, msec);
  
  r_back.set(true);
  move_new_deg(-850, 80, 40, -90, 0.4);
  TankMove(40, 40);
  wait(400, msec);
  drivertrainStop(brake);
  r_back.set(false);
  // wait(10000000, msec); //測試用wait

  cata.stop(brake);
  move_new_deg(1000, 60, 40, 223, 0.65);
  // wait(1000, msec); //測試用wait
  // move_turn(222, 0.5);
  move_new_deg(2400, 60, 40, 222, 0.6);
  // wait(1000, msec); //測試用wait

  move_turn(338, 0.5);
  wait(1000, msec); //測試用wait
  l_back.set(true);
  move_new_deg(-400, 70, 70, 285, 0.9);
  wait(1000, msec); //測試用wait
  wait(100, msec);
  l_back.set(false);
  // wait(1000, msec); //測試用wait

  move_new_deg(-800, 50, 50, 270, 0.6);
  wait(100, msec);
  move_new_deg(-1200, 35, 40, 270, 0.3);
  
  wait(100, msec);
  move_new_deg(2500, 70, 40, 305, 0.4);
  // wait(1000, msec); //測試用wait
  move_turn(254, 0.5);
  TankMove(-17, -17);
  wait(300, msec);
  drivertrainStop(brake);
}

//touch barrier at last
void near_final_shoot(){

  // wait(10000000000,msec);
  // task start_cata = task(task_starting);
  // Inertial.setHeading(45,deg);
  Inertial.setHeading(0,deg);
  intake.spin(fwd, 600, rpm);
  
  move_new_deg(2200, 80, 50, 22, 0.63);
  wait(100, msec);
  cata.spin(reverse, 50, rpm);
  move_new_deg(140, 20, 20, 22, 0.35);
  wait(300, msec);
  
  move_new_deg(-500, 40, 70, -90, 0.7);
  r_back.set(true);
  wait(100, msec);
  
  // wait(100, msec);
  move_new_deg(-600, 70, 40, -90, 0.4);
  intake.stop(brake);
  TankMove(40, 40);
  wait(600, msec);
  drivertrainStop(brake);
  r_back.set(false);

  // wait(10000000, msec); //測試用wait

  move_new_deg(1000, 60, 45, 223, 0.74);
  cata.stop(brake);
  cata.spin(fwd, 200, rpm);
  wait(500, msec);
  move_turn(233, 0.6);
  intake.spin(reverse, 600, rpm);
  wait(140, msec);
  intake.stop(hold);
  intake.spin(fwd, 600, rpm);
  wait(900, msec);
  // wait(100000000, msec); //測試用wait
  // move_turn(222, 0.5);
  move_new_deg(1500, 60, 40, 222, 0.6);
  // wait(1000, msec); //測試用wait

  move_turn(345, 0.58);
  cata.stop(brake);
  // wait(1000, msec); //測試用wait
  wait(100, msec);
  l_back.set(true);
  wait(100, msec);
  move_new_deg(-400, 50, 30, 285, 0.65);
  // wait(1000, msec); //測試用wait
  wait(100, msec);
  l_back.set(false);
  wait(100, msec);
  // wait(1000, msec); //測試用wait

  move_new_deg(-800, 60, 55, 270, 0.7);
  wait(100, msec);
  move_new_deg(-1250, 70, 40, 270, 0.3);
  
  wait(100, msec);
  move_new_deg(2000, 70, 40, 285, 0.4);
  // wait(1000, msec); //測試用wait
  move_turn(280, 0.5);
  TankMove(-17, -17);
  wait(250, msec);
  drivertrainStop(brake);
  TankMove(0, -17);
  wait(100, msec);
  drivertrainStop(brake);
}

void near_awp_only(){

  Inertial.setHeading(40,deg);
  move_new_deg(300, 50, 40, 40, 0.4);
  wait(500, msec); //測試用wait
  l_back.set(true);
  wait(200, msec); //測試用wait
  move_new_deg(-300, 70, 70, 10, 1.2);
  // wait(200, msec); //測試用wait
  // wait(1000, msec); //測試用wait
  r_back.set(true);
  l_back.set(false);
  wait(100, msec); //測試用wait
  // wait(1000, msec); //測試用wait

  // move_new_deg(-800, 50, 70, 0, 0.6);
  move_new_deg(-350, 30, 30, 10, 1.2);
  move_turn(0, 0.5);
  // wait(1000, msec); //測試用wait
  wait(100, msec);
  move_new_deg(-1420, 30, 20, 0, 0.4);//1150

}

void near_final_simple(){

  Inertial.setHeading(40,deg);
  move_new_deg(300, 50, 40, 40, 0.4);
  wait(500, msec); //測試用wait
  l_back.set(true);
  wait(200, msec); //測試用wait
  move_new_deg(-300, 70, 70, 10, 1.2);
  // wait(200, msec); //測試用wait
  // wait(1000, msec); //測試用wait
  r_back.set(true);
  l_back.set(false);
  wait(100, msec); //測試用wait
  // wait(1000, msec); //測試用wait

  move_new_deg(-800, 50, 70, 0, 0.6);
  // move_turn(0, 0.5);
  // wait(1000, msec); //測試用wait
  wait(100, msec);
  move_new_deg(-900, 70, 20, 0, 0.4);
  r_back.set(false);

  wait(100, msec);
  move_new_deg(2600, 70, 40, 45, 0.4);
  // wait(1000, msec); //測試用wait
  move_turn(180, 0.5);
  TankMove(30, 30);
  wait(700, msec);
  drivertrainStop(brake);
  r_back.set(true);

}

void near_stop_middle(){
  Inertial.setHeading(20,deg);
  intake.spin(reverse, 600, rpm);
  
  move_new_deg(1700, 100, 30, 20, 0.3);
  l_front.set(true);
  r_front.set(true);
  r_back.set(true);
  move_turn(240, 0.40);
  l_front.set(false);
  r_front.set(false);
  
}

// int task_lower_cata(){
//   cata.spin(reverse, 200, rpm);
//   wait(100, msec);
//   while(rotation_sensor.angle()<50){
//     cata.spin(reverse, 200, rpm);
//   }
//   // Controller1.rumble(".-.");
//   cata.stop(coast);
//   return 0;
// }

void auto_skills_cross(){
  Inertial.setHeading(40,deg);
  // cata.spin(fwd, 300, rpm);
  // // move_turn(40, 0.6);
  move_new_deg(-500, 30, 40, 40, 0.45);
  // wait(3000, msec);
  move_turn(-20, 0.5);
  r_back.set(true);

  while(Brain.Timer.time(seconds)<37){ //43
    // PID_adjust(530, 2.2, 0.7, 2.0);
  }
  cata.stop(coast);
  // wait(1000, msec); //測試用wait
  r_back.set(false);
  intake.spin(reverse, 600, rpm);
  move_new_deg(4200, 90, 70, 275, 0.9);
  move_turn(0, 0.55);
  chassis.spin(fwd, 600, rpm);
  wait(150, msec);
  chassis.stop(brake);
  chassis.spin(reverse, 12, volt);
  wait(1950, msec);
  chassis.stop(brake);
  wait(100, msec);
  chassis.spin(fwd, 40, pct);
  wait(800, msec);
  drivertrainStop(brake);
  wait(100, msec);
  TankMove(-20, 0);
  wait(220, msec);
  drivertrainStop(brake);
  l_front.set(true);
  r_front.set(true);
  // while(Inertial.heading()<9){
  //   TankMove(-20, 0);
  // }
  // drivertrainStop(brake);

  // front_wing.set(true);
  // intake_piston.set(true);

  // wait(1000, msec); //測試用wait
  // move_new_deg(700, 75, 40, 5, 0.4);
  // wait(1000, msec); //測試用wait
  TankMove(-80, -80);
  wait(1000, msec);
  drivertrainStop(brake);
  wait(100, msec);
  l_front.set(false);
  r_front.set(false);

  move_new_deg(-2250, 80, 70, -80, 0.65);
  // wait(1000, msec); //測試用wait
  move_turn(340, 0.5);
  l_front.set(true);
  r_front.set(true);
  // wait(1000, msec); //測試用wait
  move_new_deg(700, 75, 40, 340, 0.4);
  // wait(1000, msec); //測試用wait
  TankMove(-80, -80);
  wait(600, msec);
  drivertrainStop(brake);
  wait(100, msec);
  l_front.set(false);
  r_front.set(false);

  r_back.set(true);

  move_new_deg(-3000, 70, 60, -130, 0.7);
  // move_new_deg(-500, 50, 40, 230, 0.4);
  while(Inertial.heading()>150){
    TankMove(40, 0);
  }
  drivertrainStop(brake);
  r_back.set(true);
  move_new_deg(-1000, 70, 60, 90, 0.37);
  TankMove(80, 80);
  wait(600, msec);
  drivertrainStop(brake);
  move_new_deg(400, 60, 40, 90, 0.4);
  TankMove(80, 80);
  wait(600, msec);
  drivertrainStop(brake);
  move_new_deg(400, 60, 40, 90, 0.4);
  TankMove(80, 80);
  wait(600, msec);
  drivertrainStop(brake);
  move_new_deg(200, 60, 40, 90, 0.4);

}

void auto_skills(){
  Inertial.setHeading(43,deg);
  move_new_deg(-500, 30, 40, 43, 0.45);
  move_turn(-22, 0.37);
  r_back.set(true);

  while(Brain.Timer.time(seconds)<26){ //33
    // PID_adjust(530, 2.2, 0.7, 2.0);
    cata.spin(fwd, 12, volt);
  }
  cata.stop(coast);
  // wait(1000, msec); //測試用wait
  r_back.set(false);\

  move_turn(220, 0.43);
  // wait(1000, msec); //測試用wait
  move_new_deg(-800, 75, 30, 220, 0.4);
  wait(100, msec);
  move_turn(175, 0.4);
  // wait(10000000000, msec); //測試用wait

  move_new_deg(-3500, 70, 40, 180, 0.4); //轉彎到 1200
  // wait(1000, msec); //測試用wait
  move_new_deg(-200, 40, 25, 90, 0.35);
  r_back.set(true);
  l_back.set(true);
  wait(100, msec); //測試用wait
  while(Inertial.heading()>49){
    TankMove(30, 0);
  }
  drivertrainStop(brake);
  wait(100, msec);
  // wait(1000, msec); //測試用wait
  move_new_deg(-450, 20, 30, 35, 0.4);
  // wait(1000, msec); //測試用wait
  r_back.set(false);
  l_back.set(false);

  move_new_deg(900, 60, 85, 160, 0.4);
  // wait(1000, msec); //測試用wait
  move_new_deg(-1200, 60, 50, 90, 0.37);
  TankMove(55, 55);
  wait(750, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait
  move_new_deg(300, 60, 40, 100, 0.5);
  TankMove(70, 70);
  wait(700, msec);
  drivertrainStop(brake);

  move_new_deg(1480, 60, 70, 180, 0.5);
  // wait(10000000, msec); //測試用wait
  wait(100, msec);
  move_turn(89, 0.4);

  l_back.set(true);
  r_back.set(true);
  // wait(1000, msec); //測試用wait
  move_new_deg(-750, 30, 30, 90, 0.35);
  // wait(1000, mse c); //測試用wait
  l_back.set(false);
  move_new_deg(-900, 20, 20, 90, 0.35);
  wait(100, msec);
  move_new_deg(600, 70, 30, 90, 0.3);
  // wait(1000, msec); //測試用wait

  move_turn(0, 0.43);
  // r_back.set(true);
  // move_new_deg(-600, 80, 40, 16, 0.4);
  // wait(1000, msec); //測試用wait
  move_new_deg(-1800, 35, 20, 110, 0.1);//1480
  // wait(1000, msec); //測試用wait
  // while(Inertial.heading()<130){
  //   TankMove(0, 40);
  // }
  // drivertrainStop(brake);
  // wait(1000, msec); //測試用wait
  move_turn(152, 0.37);
  // wait(1000, msec); //測試用wait
  l_back.set(true);
  move_new_deg(-300, 50, 40, 152, 0.4);
  // wait(1000, msec); //測試用wait
  TankMove(40, 52);
  wait(1000, msec);
  drivertrainStop(brake);
  // wait(1000000, msec);
  
  //準備推第二次
  move_new_deg(300, 70, 50, 180, 0.3);
  l_back.set(false);
  r_back.set(false);
  move_turn(0, 0.39);
  r_back.set(true);

  move_new_deg(-1900, 25, 20, 110, 0.1);
  // wait(1000, msec); //測試用wait
  
  // wait(1000, msec); //測試用wait
  // while(Inertial.heading()<150){
  //   TankMove(0, 40);
  // }
  // drivertrainStop(brake);
  move_turn(200, 0.39);
  // wait(1000, msec); //測試用wait
  l_back.set(true);
  r_back.set(true);

  move_new_deg(-700, 70, 40, 200, 0.3);
  r_back.set(false);
  TankMove(45, 40);
  wait(900, msec);
  drivertrainStop(brake);

  //去推旁邊
  move_new_deg(300, 70, 50, 180, 0.3);
  // r_back.set(false);
  move_new_deg(800, 70, 40, 180, 0.3);
  // wait(1000, msec); //測試用wait
  // TankMove(-30, -30);
  // wait(300, msec);
  // drivertrainStop(brake);

  move_turn(120, 0.42);
  // wait(1000, msec); //測試用wait
  r_back.set(true);
  l_back.set(true);
  move_new_deg(-400, 30, 20, 120, 0.3, 1.5);
  if(force_stop == true){
    move_new_deg(300, 50, 20, 120, 0.3);
    move_turn(121, 0.42);
    force_stop = false;
  }
  l_back.set(false);
  r_back.set(false);
  wait(1000, msec);
  move_new_deg(-1600, 30, 20, 120, 0.3, 3.0);
  if(force_stop == true){
    move_new_deg(400, 50, 20, 120, 0.3);
    force_stop = false;
  }
  l_back.set(true);
  // wait(10000000, msec); //測試用wait
  while(Inertial.heading()<200){
    TankMove(0, 40);
  }
  drivertrainStop(brake);
  // l_back.set(false);
  // wait(1000, msec); //測試用wait
  move_new_deg(-800, 65, 55, 270, 0.36);
  TankMove(80, 80);
  wait(500, msec);
  drivertrainStop(brake);
  move_new_deg(200, 60, 40, 260, 0.4);
  intake.spin(reverse, 600, rpm);

  TankMove(80, 80);
  wait(450, msec);
  drivertrainStop(brake);
  move_new_deg(200, 50, 40, 260, 0.4);

}

void auto_skills_old_side(){
  Inertial.setHeading(40,deg);
  // cata.spin(fwd, 300, rpm);
  // // move_turn(40, 0.6);
  move_new_deg(-500, 30, 40, 40, 0.45);
  // wait(3000, msec);
  move_turn(-22, 0.5);
  r_back.set(true);

  while(Brain.Timer.time(seconds)<35){ //43
    cata.spin(fwd, 10.2, volt);
  }
  cata.stop(coast);
  // wait(1000, msec); //測試用wait
  r_back.set(false);

  move_turn(217, 0.5);
  // wait(1000, msec); //測試用wait
  move_new_deg(-700, 60, 44, 170, 0.52);
  wait(100, msec);
  // TankMove(0, -30);
  // wait(450, msec);
  // drivertrainStop(brake);
  move_turn(176, 0.45);
  // wait(1000, msec); //測試用wait

  // waitUntil(Brain.Timer.time(seconds)>40);
  // wait(1000000000, msec); //測試用wait

  cata.spin(fwd, 200, rpm);

  move_new_deg(-4300, 90, 40, 180, 0.6); //轉彎到 1200
  // wait(1000000000, msec); //測試用wait
  cata.stop(coast);

  move_new_deg(-1800, 80, 80, 90, 0.64);
  // wait(1000, msec); //測試用wait

  TankMove(100, 100);
  wait(700, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait
  move_new_deg(400, 100, 40, 100, 0.5);
  TankMove(100, 100);
  wait(700, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait

  // move_new_deg(1100, 70, 40, 0, 0.5);
  // wait(1000, msec); //測試用wait
  move_new_deg(200, 60, 40, 100, 0.5);
  // wait(1000, msec); //測試用wait
  move_turn(16, 0.6);
  // wait(1000, msec); //測試用wait
  // r_back.set(true);
  
  move_new_deg(-800, 80, 40, 16, 0.4);
  l_back.set(true);
  move_new_deg(-600, 80, 40, 16, 0.4);
  // wait(1000, msec); //測試用wait
  // l_back.set(false);
  move_new_deg(-1370, 50, 40, 110, 0.15);
  l_back.set(false);
  r_back.set(true);
  // wait(1000, msec); //測試用wait
  while(Inertial.heading()<150){
    TankMove(0, 40);
  }
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait
  move_turn(180, 0.6);
  l_back.set(true);
  r_back.set(true);

  move_new_deg(-300, 70, 40, 180, 0.4);
  TankMove(100, 100);
  wait(500, msec);
  drivertrainStop(brake);
  // wait(1000, msec); //測試用wait

  move_new_deg(300, 70, 50, 180, 0.3);
  l_back.set(false);
  r_back.set(false);
  move_turn(0, 0.6);
  r_back.set(true);

  move_new_deg(-1600, 70, 50, 90, 0.6);
  // wait(1000, msec); //測試用wait
  
  // wait(1000, msec); //測試用wait
  while(Inertial.heading()<150){
    TankMove(0, 40);
  }
  drivertrainStop(brake);
  move_turn(190, 0.6);
  l_back.set(true);
  r_back.set(true);

  move_new_deg(-700, 70, 40, 190, 0.3);
  TankMove(70, 70);
  wait(600, msec);
  drivertrainStop(brake);
  wait(100, msec); //測試用wait
  move_new_deg(1500, 70, 40, 200, 0.3);
  // wait(1000, msec); //測試用wait
  // TankMove(-30, -30);
  // wait(300, msec);
  // drivertrainStop(brake);

  move_turn(122, 0.52);
  l_back.set(false);
  r_back.set(true);
  move_new_deg(-2600, 70, 40, 122, 0.3);
  r_back.set(false);
  // wait(1000, msec); //測試用wait
  while(Inertial.heading()<210){
    TankMove(0, 40);
  }
  drivertrainStop(brake);
  // l_back.set(false);
  // wait(1000, msec); //測試用wait
  move_new_deg(-1000, 70, 65, 270, 0.48);
  TankMove(80, 80);
  wait(550, msec);
  drivertrainStop(brake);
  move_new_deg(450, 60, 40, 270, 0.4);
  intake.spin(reverse, 600, rpm);

  TankMove(80, 80);
  wait(600, msec);
  drivertrainStop(brake);
  move_new_deg(200, 60, 40, 270, 0.4);

}

void test(){
}