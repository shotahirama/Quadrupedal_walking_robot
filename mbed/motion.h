#ifndef __MOTION_H__
#define __MOTION_H__

#include "KRS2552.h"

class Motion
{
public:

    /**
    - コンストラクタ
    */
    Motion() {
        servo.angle(1,0);
        servo.angle(3,0);
        servo.angle(5,0);
        servo.angle(7,0);
        servo.angle(2,0);
        servo.angle(4,0);
        servo.angle(6,0);
        servo.angle(8,0);
        wait_ms(500);
    }
    
    void init(){
        servo.angle(1,0);
        servo.angle(3,0);
        servo.angle(5,0);
        servo.angle(7,0);
        servo.angle(2,0);
        servo.angle(4,0);
        servo.angle(6,0);
        servo.angle(8,0);
    }

    /**
        - walk
        - 歩く
    */
    void walk() {
        motion1();
        wait_ms(500);
        pos3(1,30);
        wait_ms(500);

        motion2();
        wait_ms(500);
        pos3(5,30);
        wait_ms(500);

        motion3();
        wait_ms(500);
        pos3(7,30);
        wait_ms(500);

        motion4();
        wait_ms(500);
        pos3(3,30);
        wait_ms(500);
    }
    
    void walkRight(){
        int l = 30;
        int r = 15;
        motion13(l,r);
        wait_ms(500);
        pos3(1,30);
        wait_ms(500);

        motion14(l,r);
        wait_ms(500);
        pos3(5,15);
        wait_ms(500);

        motion15(l,r);
        wait_ms(500);
        pos3(7,15);
        wait_ms(500);

        motion16(l,r);
        wait_ms(500);
        pos3(3,30);
        wait_ms(500);
    }
    
    void walkLeft(){
        int l = 15;
        int r = 30;
        motion13(l,r);
        wait_ms(500);
        pos3(1,30);
        wait_ms(500);

        motion14(l,r);
        wait_ms(500);
        pos3(5,15);
        wait_ms(500);

        motion15(l,r);
        wait_ms(500);
        pos3(7,15);
        wait_ms(500);

        motion16(l,r);
        wait_ms(500);
        pos3(3,30);
        wait_ms(500);
    }

    /**
        - back
        - 歩く
    */
    void back() {
        motion4();
        wait_ms(500);
        pos1(3,30);
        wait_ms(500);

        motion3();
        wait_ms(500);
        pos1(7,30);
        wait_ms(500);

        motion2();
        wait_ms(500);
        pos1(5,30);
        wait_ms(500);

        motion1();
        wait_ms(500);
        pos1(1,30);
        wait_ms(500);
    }
    /**
        - turnL
        - その場左回転
    */

    void turnL() {

        motion9();
        wait_ms(300);

        motion5();
        wait_ms(300);

        motion6();
        wait_ms(300);

        motion7();
        wait_ms(300);

        motion8();
        wait_ms(300);
        init();
        wait_ms(300);

    }
    
    /**
        - turnR
        - その場左回転
    */

    void turnR() {

        motion9();
        wait_ms(300);

        motion5();
        wait_ms(300);

        motion10();
        wait_ms(300);

        motion11();
        wait_ms(300);

        motion12();
        wait_ms(300);
        init();
        wait_ms(300);

    }

    /**
        - updown
        - 対角線に上げ下げ
    */
    void updown() {
        pos2(1);
        pos2(3);
        pos2(5);
        pos2(7);
        wait_ms(500);
        pos2(1);
        pos4(3,30);
        pos2(5);
        pos4(7,30);
        wait_ms(500);
        pos2(1);
        pos2(3);
        pos2(5);
        pos2(7);
        wait_ms(500);
        pos4(1,30);
        pos2(3);
        pos4(5,30);
        pos2(7);
        wait_ms(500);
    }


private:
    KRS2552 servo;
    /**
    - initChecker
    - 初期値が0でないときに正負の符号をそろえるためのもの
    -
    - 返り値: 1 or -1
    */
    int initChecker(int num) {
        int re = 0;
        switch (num) {
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
    - 返り値: 1 or -1
    */
    int flontChecker(int num) {
        int re = 0;
        switch (num) {
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
    - pos
    - 歩行ポジション1～4
    -       4
    -
    -   1   2   3
    */
    void pos1(int num, int ang) {
        servo.angle(num, -flontChecker(num) * ang);
        servo.angle(num + 1,0);
    }
    void pos2(int num) {
        servo.angle(num,0);
        servo.angle(num + 1,0);
    }
    void pos3(int num, int ang) {
        servo.angle(num,flontChecker(num) *  ang);
        servo.angle(num + 1,0);
    }
    void pos4(int num, int ang) {
        servo.angle(num, 0);
        servo.angle(num + 1,-ang);
    }

    void widePos1(int num) {
        servo.angle(num, -flontChecker(num) * 45);
        servo.angle(num + 1,0);
    }
    void widePos2(int num) {
        servo.angle(num,0);
        servo.angle(num + 1,0);
    }
    void widePos3(int num) {
        servo.angle(num,flontChecker(num) *  45);
        servo.angle(num + 1,0);
    }
    void widePos4(int num) {
        servo.angle(num, 0);
        servo.angle(num + 1,-30);
    }

    /**
        - motion
        - 歩行のための全体の足の位置1～4
    */
    void motion1() {
        pos1(5,30);
        pos2(7);
        pos3(3,30);
        pos4(1,45);
    }

    void motion2() {
        pos1(7,30);
        pos2(3);
        pos3(1,30);
        pos4(5,45);
    }

    void motion3() {
        pos1(3,30);
        pos2(1);
        pos3(5,30);
        pos4(7,45);
    }

    void motion4() {
        pos1(1,30);
        pos2(5);
        pos3(7,30);
        pos4(3,45);
    }

    void motion5() {
        pos4(1,30);
        pos2(3);
        pos4(5,30);
        pos2(7);
    }

    void motion6() {
        pos1(1,45);
        pos2(3);
        pos3(5,45);
        pos2(7);
    }

    void motion7() {
        pos1(1,45);
        pos4(3,30);
        pos3(5,45);
        pos4(7,30);
    }
    void motion8() {
        pos1(1,45);
        pos1(3,45);
        pos3(5,45);
        pos3(7,45);
    }
    void motion9() {
        pos2(1);
        pos2(3);
        pos2(5);
        pos2(7);
    }
    void motion10() {
        pos3(1,45);
        pos2(3);
        pos1(5,45);
        pos2(7);
    }
    void motion11() {
        pos3(1,45);
        pos4(3,30);
        pos1(5,45);
        pos4(7,30);
    }
    void motion12() {
        pos3(1,45);
        pos3(3,45);
        pos1(5,45);
        pos1(7,45);
    }
    void motion13(int l,int r) {
        pos1(5,r);
        pos2(7);
        pos3(3,l);
        pos4(1,45);
    }
    void motion14(int l,int r) {
        pos1(7,r);
        pos2(3);
        pos3(1,l);
        pos4(5,45);
    }
    void motion15(int l,int r) {
        pos1(3,l);
        pos2(1);
        pos3(5,r);
        pos4(7,45);
    }
    void motion16(int l,int r) {
        pos1(1,l);
        pos2(5);
        pos3(7,r);
        pos4(3,45);
    }
    


};



#endif



