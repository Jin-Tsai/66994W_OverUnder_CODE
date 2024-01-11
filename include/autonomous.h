#include "vex.h"

//  name                go middle first   shoot to opp    awp_mission     stops at matchload
//  near_awp_only       ✖                 ✖               ✔              ✖
//  near_final_simple   ✖                 ✖               ✖              ✔
//  near_final_shoot    ✔(turn->shoot)    ✔               ✖              ✔
//  near_awp_shoot      ✔(turn->shoot)    ✔               ✔              ✖
//  near_final_stealmid ✔(shoot->turn)    ✔               ✔              ✔
//  near_stop_middle    ✔                 ✖               ✖              ✖

void near_awp_only();
void near_final_simple();
void near_final_shoot();
void near_awp_shoot();
void near_final_stealmid();
void near_stop_middle();

//  name                middle first   touch elev.   elev. ball  ball_num    uturn  awp_scoop
//  far_6_elevation     ✖              ✖            ✔           5           _      ✖
//  far_awp_no_bar      ✖              ✖            ✔           5           _      ✔
//  far_4_bar           ✖              ✔            ✔           4           _      ✔
//  far_5_middle        ✔              ✖            ✔           5           ✔      ✔
//  far_6_middle        ✔              ✖            ✔           6           ✔      ✔
//  

void far_6_elevation();
void far_awp_no_bar();
void far_4_bar();
void far_6_middle();
void far_5_middle();

void auto_skills();//new
void auto_skills_old_side();//tunnel
void auto_skills_cross();//cross_long_barrier


int task_open_rwing();
int task_close_rwing();
int task_starting();
int task_lower_cata();
int task_cata_pos();

void test();
