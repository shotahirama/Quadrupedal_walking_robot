/*--------------------------------------------------------------------------------------------------------------
*   Name:       main.cpp
*   Author:     S.Hirama
*               R.Imai
*   Created:    2015 / ?? / ??
*   Last Date:  2015 / 11 / 18
*   Note:
*
*--------------------------------------------------------------------------------------------------------------*/

#include "KRS2552.h"

KRS2552 servo;

/**
    - initChecker
    - 初期値が0でないときに正負の符号をそろえるためのもの
*/
int initChecker(int num){
    int re = 0;
    switch (num){
        case 1:
        case 5:
            re = -1;
            break;
        case 3:
        case 7:
            re = 1;
            break;
    }
    return re;
}

/**
    - flontChecker
    - 前部分に当たる角度の正負の符号をそろえるためのもの
*/
int flontChecker(int num){
    int re = 0;
    switch (num){
        case 1:
        case 3:
            re = 1;
            break;
        case 5:
        case 7:
            re = -1;
            break;
    }
    return re;
}

/**
    - init
    - 初期位置
*/
void init(){
    servo.angle(1,0);
    servo.angle(3,0);
    servo.angle(5,0);
    servo.angle(7,0);
    servo.angle(2,0);
    servo.angle(4,0);
    servo.angle(6,0);
    servo.angle(8,0);
    wait(1);
}

/**
    - pos
    - 歩行ポジション1～4
*/
void pos1(int num){
    servo.angle(num,/*initChecker(num) * 22.5*/ -flontChecker(num) * 30);
    servo.angle(num + 1,0);
}
void pos2(int num){
    servo.angle(num,/*initChecker(num) * 22.5*/0);
    servo.angle(num + 1,0);
}
void pos3(int num){
    servo.angle(num,/*initChecker(num) * 22.5 + */flontChecker(num) *  30);
    servo.angle(num + 1,0);
}
void pos4(int num){
    servo.angle(num,/*initChecker(num) * 22.5*/ 0);
    servo.angle(num + 1,-30);
}

void widePos1(int num){
    servo.angle(num,/*initChecker(num) * 22.5*/ -flontChecker(num) * 45);
    servo.angle(num + 1,0);
}
void widePos2(int num){
    servo.angle(num,/*initChecker(num) * 22.5*/0);
    servo.angle(num + 1,0);
}
void widePos3(int num){
    servo.angle(num,/*initChecker(num) * 22.5 + */flontChecker(num) *  45);
    servo.angle(num + 1,0);
}
void widePos4(int num){
    servo.angle(num,/*initChecker(num) * 22.5*/ 0);
    servo.angle(num + 1,-30);
}


/**
    - motion
    - 歩行のための全体の足の位置1～4
*/
void motion1(){
    pos1(5);
    pos2(7);
    pos3(3);
    pos4(1);
}

void motion2(){
    pos1(7);
    pos2(3);
    pos3(1);
    pos4(5);
}

void motion3(){
    pos1(3);
    pos2(1);
    pos3(5);
    pos4(7);
}

void motion4(){
    pos1(1);
    pos2(5);
    pos3(7);
    pos4(3);
}

void motion5(){
    widePos4(1);
    widePos2(3);
    widePos2(5);
    widePos2(7);
}

void motion6(){
    widePos1(1);
    widePos4(3);
    widePos2(5);
    widePos2(7);
}

void motion7(){
    widePos1(1);
    widePos1(3);
    widePos4(5);
    widePos2(7);
}

void motion8(){
    widePos1(1);
    widePos1(3);
    widePos3(5);
    widePos4(7);
}


/**
    - updown
    - 対角線に上げ下げ
*/
void updown(){
    pos2(1);
    pos2(3);
    pos2(5);
    pos2(7);
    wait(1);
    pos2(1);
    pos4(3);
    pos2(5);
    pos4(7);
    wait(1);
    pos2(1);
    pos2(3);
    pos2(5);
    pos2(7);
    wait(1);
    pos4(1);
    pos2(3);
    pos4(5);
    pos2(7);
    wait(1);
}

/**
    - walk
    - 歩く
*/
void walk(){
    motion1();
    wait(1);
    pos3(1);
    wait(1);
    
    motion2();
    wait(1);
    pos3(5);
    wait(1);
    
    motion3();
    wait(1);
    pos3(7);
    wait(1);
    
    motion4();
    wait(1);
    pos3(3);
    wait(1);
}

void turn(){
    init();
    motion5();
    wait(1);
    pos1(1);
    wait(1);
    
    motion6();
    wait(1);
    pos1(3);
    wait(1);
    
    motion7();
    wait(1);
    pos3(5);
    wait(1);
    
    motion8();
    wait(1);
    pos3(7);
    wait(1);
}

int main()
{
    init();
    while(1){
        turn();
    }
    
    return 0;
}